cmake_minimum_required(VERSION 3.0)
project(fluent-opentelemetry-proto C)

# Include helpers
include(cmake/macros.cmake)

# Paths
set(PROTOC_BIN                "/opt/homebrew/bin/protoc")
set(PROTOC_ARGS               "--c_out=../src --proto_path=../opentelemetry/")
set(OTEL_PROTO_PATH           "opentelemetry/proto")
set(OTEL_PROTO_RELATIVE_PATH  "../${OTEL_PROTO_PATH}")

# final protoc command
set(PROTOC_COMMAND "${PROTOC_BIN} ${PROTOC_ARGS}")

# Protobuf-c headers (this is not working, I ended up copying protobuf-c headers inside include/)
set(PROTOC_HEADERS "/opt/homebrew/Cellar/protobuf-c/1.4.1_1/include/")
include_directories(PROTOC_HEADERS)

# build options
option(FLUENT_PROTO_COMMON   "Include common.proto"    "Yes")
option(FLUENT_PROTO_RESOURCE "Include resource.proto"  "Yes")
option(FLUENT_PROTO_TRACE    "Include trace.proto"     "Yes")
option(FLUENT_PROTO_LOGS     "Include logs.proto"      "Yes")
option(FLUENT_PROTO_METRICS  "Inlcude metrics.proto"    "No")

if (FLUENT_PROTO_COMMON)
	message(STATUS "processing common.proto")
	execute_process(COMMAND "${PROTOC_COMMAND} ${OTEL_PROTO_RELATIVE_PATH}/common/v1/common.proto")
	configure_file("${PROJECT_SOURCE_DIR}/src/${OTEL_PROTO_PATH}/common/v1/common.pb-c.h"
		           "${PROJECT_SOURCE_DIR}/include/${OTEL_PROTO_PATH}/common/v1/common.pb-c.h"
		           COPYONLY)
	FLUENT_OTEL_DEFINITION(FLUENT_OTEL_HAVE_COMMON)
endif()

if (FLUENT_PROTO_RESOURCE)
	message(STATUS "processing resource.proto")
	execute_process(COMMAND "${PROTOC_COMMAND} ${OTEL_PROTO_RELATIVE_PATH}/resource/v1/resource.proto")
	configure_file("${PROJECT_SOURCE_DIR}/src/${OTEL_PROTO_PATH}/resource/v1/resource.pb-c.h"
		           "${PROJECT_SOURCE_DIR}/include/${OTEL_PROTO_PATH}/resource/v1/resource.pb-c.h"
		           COPYONLY)
	FLUENT_OTEL_DEFINITION(FLUENT_OTEL_HAVE_RESOURCE)
endif()

if (FLUENT_PROTO_TRACE)
	message(STATUS "processing trace.proto")
	execute_process(COMMAND "${PROTOC_COMMAND} ${OTEL_PROTO_RELATIVE_PATH}/trace/v1/trace.proto")
	configure_file("${PROJECT_SOURCE_DIR}/src/${OTEL_PROTO_PATH}/trace/v1/trace.pb-c.h"
		           "${PROJECT_SOURCE_DIR}/include/${OTEL_PROTO_PATH}/trace/v1/trace.pb-c.h"
		           COPYONLY)
	FLUENT_OTEL_DEFINITION(FLUENT_OTEL_HAVE_TRACE)
endif()

if (FLUENT_PROTO_LOGS)
	message(STATUS "processing logs.proto")
	execute_process(COMMAND "${PROTOC_COMMAND} ${OTEL_PROTO_RELATIVE_PATH}/logs/v1/logs.proto")
	configure_file("${PROJECT_SOURCE_DIR}/src/${OTEL_PROTO_PATH}/logs/v1/logs.pb-c.h"
		           "${PROJECT_SOURCE_DIR}/include/${OTEL_PROTO_PATH}/logs/v1/logs.pb-c.h"
		           COPYONLY)
	FLUENT_OTEL_DEFINITION(FLUENT_OTEL_HAVE_LOGS)
endif()

if (FLUENT_PROTO_METRICS)
	message(STATUS "processing metrics.proto")
	execute_process(COMMAND "${PROTOC_COMMAND} ${OTEL_PROTO_RELATIVE_PATH}/logs/v1/metrics.proto")
	configure_file("${PROJECT_SOURCE_DIR}/src/${OTEL_PROTO_PATH}/metrics/v1/metrics.pb-c.h"
		           "${PROJECT_SOURCE_DIR}/include/${OTEL_PROTO_PATH}/metrics/v1/metrics.pb-c.h"
		           COPYONLY)
	FLUENT_OTEL_DEFINITION(FLUENT_OTEL_HAVE_METRICS)
endif()

configure_file(
  "${PROJECT_SOURCE_DIR}/include/fluent-otel-proto/fluent-otel-info.h.in"
  "${PROJECT_SOURCE_DIR}/include/fluent-otel-proto/fluent-otel-info.h"
  )

add_subdirectory(src)
add_subdirectory(examples)
