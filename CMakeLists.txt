cmake_minimum_required(VERSION 3.0)
project(fluent-opentelemetry-proto C)

# Include helpers
include(cmake/macros.cmake)

# Paths
set(OTEL_PROTO_PATH           "${PROJECT_SOURCE_DIR}/lib/opentelemetry-proto")
set(PROTOC_BIN                "/opt/homebrew/bin/protoc")
set(PROTOC_ARG_OUT            "--c_out=${PROJECT_BINARY_DIR}/")
set(PROTOC_ARG_PATH           "--proto_path=${OTEL_PROTO_PATH}/")

# final protoc base command
message(STATUS "base command: ${PROTOC_BIN} ${PROTOC_ARG_OUT} ${PROTOC_ARG_PATH}")

# Protobuf-c headers (this is not working, I ended up copying protobuf-c headers inside include/)
set(PROTOC_HEADERS "/opt/homebrew/Cellar/protobuf-c/1.4.1_1/include/")
include_directories(PROTOC_HEADERS)

# build options
option(FLUENT_PROTO_COMMON   "Include common.proto"    "Yes")
option(FLUENT_PROTO_RESOURCE "Include resource.proto"  "Yes")
option(FLUENT_PROTO_TRACE    "Include trace.proto"     "Yes")
option(FLUENT_PROTO_LOGS     "Include logs.proto"      "Yes")
option(FLUENT_PROTO_METRICS  "Inlcude metrics.proto"    "No")
option(FLUENT_PROTO_EXAMPLES "Add example programs"    "Yes")

if (FLUENT_PROTO_COMMON)
	message(STATUS "processing common.proto")
	set(proto_file ${OTEL_PROTO_PATH}/opentelemetry/proto/common/v1/common.proto)
	execute_process(COMMAND ${PROTOC_BIN} ${PROTOC_ARG_OUT} ${PROTOC_ARG_PATH} ${proto_file})
	include_directories(${PROJECT_BINARY_DIR}/opentelemetry/proto/common/v1/)
	FLUENT_OTEL_DEFINITION(FLUENT_OTEL_HAVE_COMMON)
endif()

if (FLUENT_PROTO_RESOURCE)
	message(STATUS "processing resource.proto")
	set(proto_file "${OTEL_PROTO_PATH}/opentelemetry/proto/resource/v1/resource.proto")
	execute_process(COMMAND ${PROTOC_BIN} ${PROTOC_ARG_OUT} ${PROTOC_ARG_PATH} ${proto_file})
	include_directories(${PROJECT_BINARY_DIR}/opentelemetry/proto/resource/v1/)
	FLUENT_OTEL_DEFINITION(FLUENT_OTEL_HAVE_RESOURCE)
endif()

if (FLUENT_PROTO_TRACE)
	message(STATUS "processing trace.proto")
	set(proto_file "${OTEL_PROTO_PATH}/opentelemetry/proto/trace/v1/trace.proto")
	execute_process(COMMAND ${PROTOC_BIN} ${PROTOC_ARG_OUT} ${PROTOC_ARG_PATH} ${proto_file})
	include_directories(${PROJECT_BINARY_DIR}/opentelemetry/proto/trace/v1/)

	message(STATUS "processing trace_service.proto")
	set(proto_file "${OTEL_PROTO_PATH}/opentelemetry/proto/collector/trace/v1/trace_service.proto")
	execute_process(COMMAND ${PROTOC_BIN} ${PROTOC_ARG_OUT} ${PROTOC_ARG_PATH} ${proto_file})
	include_directories(${PROJECT_BINARY_DIR}/opentelemetry/proto/collector/trace/v1)
	FLUENT_OTEL_DEFINITION(FLUENT_OTEL_HAVE_TRACE)
endif()

if (FLUENT_PROTO_LOGS)
	message(STATUS "processing logs.proto")
	set(proto_file "${OTEL_PROTO_PATH}/opentelemetry/proto/logs/v1/logs.proto")
	execute_process(COMMAND ${PROTOC_BIN} ${PROTOC_ARG_OUT} ${PROTOC_ARG_PATH} ${proto_file})
	include_directories(${PROJECT_BINARY_DIR}/opentelemetry/proto/logs/v1/)
	FLUENT_OTEL_DEFINITION(FLUENT_OTEL_HAVE_LOGS)

	message(STATUS "processing logs_service.proto")
	set(proto_file "${OTEL_PROTO_PATH}/opentelemetry/proto/collector/logs/v1/logs_service.proto")
	execute_process(COMMAND ${PROTOC_BIN} ${PROTOC_ARG_OUT} ${PROTOC_ARG_PATH} ${proto_file})
	include_directories(${PROJECT_BINARY_DIR}/opentelemetry/proto/collector/logs/v1/)
	FLUENT_OTEL_DEFINITION(FLUENT_OTEL_HAVE_LOGS)
endif()

if (FLUENT_PROTO_METRICS)
	message(STATUS "processing metrics.proto")
	set(proto_file "${OTEL_PROTO_PATH}/opentelemetry/proto/metrics/v1/metrics.proto")
	execute_process(COMMAND ${PROTOC_BIN} ${PROTOC_ARG_OUT} ${PROTOC_ARG_PATH} ${proto_file})
	include_directories(${PROJECT_BINARY_DIR}/opentelemetry/proto/metrics/v1/)

	message(STATUS "processing metrics_service.proto")
	set(proto_file "${OTEL_PROTO_PATH}/opentelemetry/proto/collector/metrics/v1/metrics_service.proto")
	execute_process(COMMAND ${PROTOC_BIN} ${PROTOC_ARG_OUT} ${PROTOC_ARG_PATH} ${proto_file})
	include_directories(${PROJECT_BINARY_DIR}/opentelemetry/proto/collector/logs/v1/)
	FLUENT_OTEL_DEFINITION(FLUENT_OTEL_HAVE_METRICS)
endif()

configure_file(
  "${PROJECT_SOURCE_DIR}/include/fluent-otel-proto/fluent-otel-info.h.in"
  "${PROJECT_SOURCE_DIR}/include/fluent-otel-proto/fluent-otel-info.h"
  )

add_subdirectory(src)

if (FLUENT_PROTO_EXAMPLES)
	add_subdirectory(examples)
endif()
