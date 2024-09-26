/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: opentelemetry/proto/collector/trace/v1/trace_service.proto */

#ifndef PROTOBUF_C_opentelemetry_2fproto_2fcollector_2ftrace_2fv1_2ftrace_5fservice_2eproto__INCLUDED
#define PROTOBUF_C_opentelemetry_2fproto_2fcollector_2ftrace_2fv1_2ftrace_5fservice_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1005000 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif

#include "opentelemetry/proto/trace/v1/trace.pb-c.h"

typedef struct Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceRequest Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceRequest;
typedef struct Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceResponse Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceResponse;
typedef struct Opentelemetry__Proto__Collector__Trace__V1__ExportTracePartialSuccess Opentelemetry__Proto__Collector__Trace__V1__ExportTracePartialSuccess;


/* --- enums --- */


/* --- messages --- */

struct  Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceRequest
{
  ProtobufCMessage base;
  /*
   * An array of ResourceSpans.
   * For data coming from a single resource this array will typically contain one
   * element. Intermediary nodes (such as OpenTelemetry Collector) that receive
   * data from multiple origins typically batch the data before forwarding further and
   * in that case this array will contain multiple elements.
   */
  size_t n_resource_spans;
  Opentelemetry__Proto__Trace__V1__ResourceSpans **resource_spans;
};
#define OPENTELEMETRY__PROTO__COLLECTOR__TRACE__V1__EXPORT_TRACE_SERVICE_REQUEST__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&opentelemetry__proto__collector__trace__v1__export_trace_service_request__descriptor) \
    , 0,NULL }


struct  Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceResponse
{
  ProtobufCMessage base;
  /*
   * The details of a partially successful export request.
   * If the request is only partially accepted
   * (i.e. when the server accepts only parts of the data and rejects the rest)
   * the server MUST initialize the `partial_success` field and MUST
   * set the `rejected_<signal>` with the number of items it rejected.
   * Servers MAY also make use of the `partial_success` field to convey
   * warnings/suggestions to senders even when the request was fully accepted.
   * In such cases, the `rejected_<signal>` MUST have a value of `0` and
   * the `error_message` MUST be non-empty.
   * A `partial_success` message with an empty value (rejected_<signal> = 0 and
   * `error_message` = "") is equivalent to it not being set/present. Senders
   * SHOULD interpret it the same way as in the full success case.
   */
  Opentelemetry__Proto__Collector__Trace__V1__ExportTracePartialSuccess *partial_success;
};
#define OPENTELEMETRY__PROTO__COLLECTOR__TRACE__V1__EXPORT_TRACE_SERVICE_RESPONSE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&opentelemetry__proto__collector__trace__v1__export_trace_service_response__descriptor) \
    , NULL }


struct  Opentelemetry__Proto__Collector__Trace__V1__ExportTracePartialSuccess
{
  ProtobufCMessage base;
  /*
   * The number of rejected spans.
   * A `rejected_<signal>` field holding a `0` value indicates that the
   * request was fully accepted.
   */
  int64_t rejected_spans;
  /*
   * A developer-facing human-readable message in English. It should be used
   * either to explain why the server rejected parts of the data during a partial
   * success or to convey warnings/suggestions during a full success. The message
   * should offer guidance on how users can address such issues.
   * error_message is an optional field. An error_message with an empty value
   * is equivalent to it not being set.
   */
  char *error_message;
};
#define OPENTELEMETRY__PROTO__COLLECTOR__TRACE__V1__EXPORT_TRACE_PARTIAL_SUCCESS__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&opentelemetry__proto__collector__trace__v1__export_trace_partial_success__descriptor) \
    , 0, (char *)protobuf_c_empty_string }


/* Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceRequest methods */
void   opentelemetry__proto__collector__trace__v1__export_trace_service_request__init
                     (Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceRequest         *message);
size_t opentelemetry__proto__collector__trace__v1__export_trace_service_request__get_packed_size
                     (const Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceRequest   *message);
size_t opentelemetry__proto__collector__trace__v1__export_trace_service_request__pack
                     (const Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceRequest   *message,
                      uint8_t             *out);
size_t opentelemetry__proto__collector__trace__v1__export_trace_service_request__pack_to_buffer
                     (const Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceRequest   *message,
                      ProtobufCBuffer     *buffer);
Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceRequest *
       opentelemetry__proto__collector__trace__v1__export_trace_service_request__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   opentelemetry__proto__collector__trace__v1__export_trace_service_request__free_unpacked
                     (Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceRequest *message,
                      ProtobufCAllocator *allocator);
/* Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceResponse methods */
void   opentelemetry__proto__collector__trace__v1__export_trace_service_response__init
                     (Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceResponse         *message);
size_t opentelemetry__proto__collector__trace__v1__export_trace_service_response__get_packed_size
                     (const Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceResponse   *message);
size_t opentelemetry__proto__collector__trace__v1__export_trace_service_response__pack
                     (const Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceResponse   *message,
                      uint8_t             *out);
size_t opentelemetry__proto__collector__trace__v1__export_trace_service_response__pack_to_buffer
                     (const Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceResponse   *message,
                      ProtobufCBuffer     *buffer);
Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceResponse *
       opentelemetry__proto__collector__trace__v1__export_trace_service_response__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   opentelemetry__proto__collector__trace__v1__export_trace_service_response__free_unpacked
                     (Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceResponse *message,
                      ProtobufCAllocator *allocator);
/* Opentelemetry__Proto__Collector__Trace__V1__ExportTracePartialSuccess methods */
void   opentelemetry__proto__collector__trace__v1__export_trace_partial_success__init
                     (Opentelemetry__Proto__Collector__Trace__V1__ExportTracePartialSuccess         *message);
size_t opentelemetry__proto__collector__trace__v1__export_trace_partial_success__get_packed_size
                     (const Opentelemetry__Proto__Collector__Trace__V1__ExportTracePartialSuccess   *message);
size_t opentelemetry__proto__collector__trace__v1__export_trace_partial_success__pack
                     (const Opentelemetry__Proto__Collector__Trace__V1__ExportTracePartialSuccess   *message,
                      uint8_t             *out);
size_t opentelemetry__proto__collector__trace__v1__export_trace_partial_success__pack_to_buffer
                     (const Opentelemetry__Proto__Collector__Trace__V1__ExportTracePartialSuccess   *message,
                      ProtobufCBuffer     *buffer);
Opentelemetry__Proto__Collector__Trace__V1__ExportTracePartialSuccess *
       opentelemetry__proto__collector__trace__v1__export_trace_partial_success__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   opentelemetry__proto__collector__trace__v1__export_trace_partial_success__free_unpacked
                     (Opentelemetry__Proto__Collector__Trace__V1__ExportTracePartialSuccess *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceRequest_Closure)
                 (const Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceRequest *message,
                  void *closure_data);
typedef void (*Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceResponse_Closure)
                 (const Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceResponse *message,
                  void *closure_data);
typedef void (*Opentelemetry__Proto__Collector__Trace__V1__ExportTracePartialSuccess_Closure)
                 (const Opentelemetry__Proto__Collector__Trace__V1__ExportTracePartialSuccess *message,
                  void *closure_data);

/* --- services --- */

typedef struct Opentelemetry__Proto__Collector__Trace__V1__TraceService_Service Opentelemetry__Proto__Collector__Trace__V1__TraceService_Service;
struct Opentelemetry__Proto__Collector__Trace__V1__TraceService_Service
{
  ProtobufCService base;
  void (*export)(Opentelemetry__Proto__Collector__Trace__V1__TraceService_Service *service,
                 const Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceRequest *input,
                 Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceResponse_Closure closure,
                 void *closure_data);
};
typedef void (*Opentelemetry__Proto__Collector__Trace__V1__TraceService_ServiceDestroy)(Opentelemetry__Proto__Collector__Trace__V1__TraceService_Service *);
void opentelemetry__proto__collector__trace__v1__trace_service__init (Opentelemetry__Proto__Collector__Trace__V1__TraceService_Service *service,
                                                                      Opentelemetry__Proto__Collector__Trace__V1__TraceService_ServiceDestroy destroy);
#define OPENTELEMETRY__PROTO__COLLECTOR__TRACE__V1__TRACE_SERVICE__BASE_INIT \
    { &opentelemetry__proto__collector__trace__v1__trace_service__descriptor, protobuf_c_service_invoke_internal, NULL }
#define OPENTELEMETRY__PROTO__COLLECTOR__TRACE__V1__TRACE_SERVICE__INIT(function_prefix__) \
    { OPENTELEMETRY__PROTO__COLLECTOR__TRACE__V1__TRACE_SERVICE__BASE_INIT,\
      function_prefix__ ## export  }
void opentelemetry__proto__collector__trace__v1__trace_service__export(ProtobufCService *service,
                                                                       const Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceRequest *input,
                                                                       Opentelemetry__Proto__Collector__Trace__V1__ExportTraceServiceResponse_Closure closure,
                                                                       void *closure_data);

/* --- descriptors --- */

extern const ProtobufCMessageDescriptor opentelemetry__proto__collector__trace__v1__export_trace_service_request__descriptor;
extern const ProtobufCMessageDescriptor opentelemetry__proto__collector__trace__v1__export_trace_service_response__descriptor;
extern const ProtobufCMessageDescriptor opentelemetry__proto__collector__trace__v1__export_trace_partial_success__descriptor;
extern const ProtobufCServiceDescriptor opentelemetry__proto__collector__trace__v1__trace_service__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_opentelemetry_2fproto_2fcollector_2ftrace_2fv1_2ftrace_5fservice_2eproto__INCLUDED */
