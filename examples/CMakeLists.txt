set(src test-api.c)

include_directories("../include")

add_executable(test-api ${src})
target_link_libraries(test-api fluent-opentelemetry-proto)
