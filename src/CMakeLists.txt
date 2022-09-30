set(src
	fluent-otel.c
	)

include_directories(
	${PROJECT_SOURCE_DIR}/include
	"."
	)

if (FLUENT_PROTO_COMMON)
	include_directories(opentelemetry/proto/common/v1/)
	set(src ${src} opentelemetry/proto/common/v1/common.pb-c.c)
endif()

if (FLUENT_PROTO_RESOURCE)
	include_directories(opentelemetry/proto/resource/v1/)
	set(src ${src} opentelemetry/proto/resource/v1/resource.pb-c.c)
endif()

if (FLUENT_PROTO_TRACE)
	include_directories(opentelemetry/proto/trace/v1/)
	set(src ${src} opentelemetry/proto/trace/v1/trace.pb-c.c)
endif()

if (FLUENT_PROTO_LOGS)
	include_directories(opentelemetry/proto/logs/v1/)
	set(src ${src} opentelemetry/proto/logs/v1/logs.pb-c.c)
endif()

if (FLUENT_PROTO_METRICS)
	set(src ${src} opentelemetry/proto/metrics/v1/metrics.pb-c.c)
endif()

add_library(fluent-opentelemetry-proto STATIC ${src})
