set(src
	fluent-otel.c
	${PROJECT_SOURCE_DIR}/lib/protobuf-c/protobuf-c/protobuf-c.c
	)

include_directories(
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/lib/protobuf-c/protobuf-c/protobuf-c.h
	${PROJECT_BINARY_DIR}
	)

if (FLUENT_PROTO_COMMON)
	set(src ${src} ${PROJECT_BINARY_DIR}/opentelemetry/proto/common/v1/common.pb-c.c)
endif()

if (FLUENT_PROTO_RESOURCE)
	set(src ${src} ${PROJECT_BINARY_DIR}/opentelemetry/proto/resource/v1/resource.pb-c.c)
endif()

if (FLUENT_PROTO_TRACE)
	set(src ${src} ${PROJECT_BINARY_DIR}/opentelemetry/proto/trace/v1/trace.pb-c.c)
	set(src ${src} ${PROJECT_BINARY_DIR}/opentelemetry/proto/collector/trace/v1/trace_service.pb-c.c)
endif()

if (FLUENT_PROTO_LOGS)
	set(src ${src} ${PROJECT_BINARY_DIR}/opentelemetry/proto/logs/v1/logs.pb-c.c)
	set(src ${src} ${PROJECT_BINARY_DIR}/opentelemetry/proto/collector/logs/v1/logs_service.pb-c.c)
endif()

if (FLUENT_PROTO_METRICS)
	set(src ${src} ${PROJECT_BINARY_DIR}/opentelemetry/proto/metrics/v1/metrics.pb-c.c)
	set(src ${src} ${PROJECT_BINARY_DIR}/opentelemetry/proto/collector/metrics/v1/metrics_service.pb-c.c)
endif()

add_library(fluent-otel-proto STATIC ${src})
