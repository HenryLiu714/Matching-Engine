// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protocols/trademessage.proto

#include "trademessage.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

PROTOBUF_CONSTEXPR OrderMessage::OrderMessage(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.symbol_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.order_id_)*/uint64_t{0u}
  , /*decltype(_impl_.user_id_)*/uint64_t{0u}
  , /*decltype(_impl_.transaction_time_)*/uint64_t{0u}
  , /*decltype(_impl_.side_)*/0
  , /*decltype(_impl_.order_quantity_)*/0
  , /*decltype(_impl_.price_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct OrderMessageDefaultTypeInternal {
  PROTOBUF_CONSTEXPR OrderMessageDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~OrderMessageDefaultTypeInternal() {}
  union {
    OrderMessage _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 OrderMessageDefaultTypeInternal _OrderMessage_default_instance_;
PROTOBUF_CONSTEXPR OrderResponse::OrderResponse(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.symbol_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.order_id_)*/uint64_t{0u}
  , /*decltype(_impl_.user_id_)*/uint64_t{0u}
  , /*decltype(_impl_.transaction_time_)*/uint64_t{0u}
  , /*decltype(_impl_.side_)*/0
  , /*decltype(_impl_.order_quantity_)*/0
  , /*decltype(_impl_.price_)*/0
  , /*decltype(_impl_.status_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct OrderResponseDefaultTypeInternal {
  PROTOBUF_CONSTEXPR OrderResponseDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~OrderResponseDefaultTypeInternal() {}
  union {
    OrderResponse _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 OrderResponseDefaultTypeInternal _OrderResponse_default_instance_;
static ::_pb::Metadata file_level_metadata_protocols_2ftrademessage_2eproto[2];
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_protocols_2ftrademessage_2eproto[3];
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_protocols_2ftrademessage_2eproto = nullptr;

const uint32_t TableStruct_protocols_2ftrademessage_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::OrderMessage, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::OrderMessage, _impl_.order_id_),
  PROTOBUF_FIELD_OFFSET(::OrderMessage, _impl_.user_id_),
  PROTOBUF_FIELD_OFFSET(::OrderMessage, _impl_.symbol_),
  PROTOBUF_FIELD_OFFSET(::OrderMessage, _impl_.side_),
  PROTOBUF_FIELD_OFFSET(::OrderMessage, _impl_.transaction_time_),
  PROTOBUF_FIELD_OFFSET(::OrderMessage, _impl_.order_quantity_),
  PROTOBUF_FIELD_OFFSET(::OrderMessage, _impl_.price_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::OrderResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::OrderResponse, _impl_.order_id_),
  PROTOBUF_FIELD_OFFSET(::OrderResponse, _impl_.user_id_),
  PROTOBUF_FIELD_OFFSET(::OrderResponse, _impl_.symbol_),
  PROTOBUF_FIELD_OFFSET(::OrderResponse, _impl_.side_),
  PROTOBUF_FIELD_OFFSET(::OrderResponse, _impl_.transaction_time_),
  PROTOBUF_FIELD_OFFSET(::OrderResponse, _impl_.order_quantity_),
  PROTOBUF_FIELD_OFFSET(::OrderResponse, _impl_.price_),
  PROTOBUF_FIELD_OFFSET(::OrderResponse, _impl_.status_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::OrderMessage)},
  { 13, -1, -1, sizeof(::OrderResponse)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::_OrderMessage_default_instance_._instance,
  &::_OrderResponse_default_instance_._instance,
};

const char descriptor_table_protodef_protocols_2ftrademessage_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\034protocols/trademessage.proto\"\234\001\n\014Order"
  "Message\022\020\n\010order_id\030\001 \001(\004\022\017\n\007user_id\030\002 \001"
  "(\004\022\016\n\006symbol\030\003 \001(\t\022\030\n\004side\030\004 \001(\0162\n.Direc"
  "tion\022\030\n\020transaction_time\030\005 \001(\004\022\026\n\016order_"
  "quantity\030\006 \001(\002\022\r\n\005price\030\007 \001(\002\"\273\001\n\rOrderR"
  "esponse\022\020\n\010order_id\030\001 \001(\004\022\017\n\007user_id\030\002 \001"
  "(\004\022\016\n\006symbol\030\003 \001(\t\022\030\n\004side\030\004 \001(\0162\n.Direc"
  "tion\022\030\n\020transaction_time\030\005 \001(\004\022\026\n\016order_"
  "quantity\030\006 \001(\002\022\r\n\005price\030\007 \001(\002\022\034\n\006status\030"
  "\010 \001(\0162\014.OrderStatus* \n\tDirection\022\010\n\004LONG"
  "\020\000\022\t\n\005SHORT\020\001*\"\n\tOrderType\022\n\n\006MARKET\020\000\022\t"
  "\n\005LIMIT\020\001*B\n\013OrderStatus\022\013\n\007PENDING\020\000\022\n\n"
  "\006FILLED\020\001\022\013\n\007PARTIAL\020\002\022\r\n\tCANCELLED\020\003b\006p"
  "roto3"
  ;
static ::_pbi::once_flag descriptor_table_protocols_2ftrademessage_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_protocols_2ftrademessage_2eproto = {
    false, false, 525, descriptor_table_protodef_protocols_2ftrademessage_2eproto,
    "protocols/trademessage.proto",
    &descriptor_table_protocols_2ftrademessage_2eproto_once, nullptr, 0, 2,
    schemas, file_default_instances, TableStruct_protocols_2ftrademessage_2eproto::offsets,
    file_level_metadata_protocols_2ftrademessage_2eproto, file_level_enum_descriptors_protocols_2ftrademessage_2eproto,
    file_level_service_descriptors_protocols_2ftrademessage_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_protocols_2ftrademessage_2eproto_getter() {
  return &descriptor_table_protocols_2ftrademessage_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_protocols_2ftrademessage_2eproto(&descriptor_table_protocols_2ftrademessage_2eproto);
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Direction_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_protocols_2ftrademessage_2eproto);
  return file_level_enum_descriptors_protocols_2ftrademessage_2eproto[0];
}
bool Direction_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* OrderType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_protocols_2ftrademessage_2eproto);
  return file_level_enum_descriptors_protocols_2ftrademessage_2eproto[1];
}
bool OrderType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* OrderStatus_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_protocols_2ftrademessage_2eproto);
  return file_level_enum_descriptors_protocols_2ftrademessage_2eproto[2];
}
bool OrderStatus_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}


// ===================================================================

class OrderMessage::_Internal {
 public:
};

OrderMessage::OrderMessage(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:OrderMessage)
}
OrderMessage::OrderMessage(const OrderMessage& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  OrderMessage* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.symbol_){}
    , decltype(_impl_.order_id_){}
    , decltype(_impl_.user_id_){}
    , decltype(_impl_.transaction_time_){}
    , decltype(_impl_.side_){}
    , decltype(_impl_.order_quantity_){}
    , decltype(_impl_.price_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.symbol_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.symbol_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_symbol().empty()) {
    _this->_impl_.symbol_.Set(from._internal_symbol(), 
      _this->GetArenaForAllocation());
  }
  ::memcpy(&_impl_.order_id_, &from._impl_.order_id_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.price_) -
    reinterpret_cast<char*>(&_impl_.order_id_)) + sizeof(_impl_.price_));
  // @@protoc_insertion_point(copy_constructor:OrderMessage)
}

inline void OrderMessage::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.symbol_){}
    , decltype(_impl_.order_id_){uint64_t{0u}}
    , decltype(_impl_.user_id_){uint64_t{0u}}
    , decltype(_impl_.transaction_time_){uint64_t{0u}}
    , decltype(_impl_.side_){0}
    , decltype(_impl_.order_quantity_){0}
    , decltype(_impl_.price_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.symbol_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.symbol_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

OrderMessage::~OrderMessage() {
  // @@protoc_insertion_point(destructor:OrderMessage)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void OrderMessage::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.symbol_.Destroy();
}

void OrderMessage::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void OrderMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:OrderMessage)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.symbol_.ClearToEmpty();
  ::memset(&_impl_.order_id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.price_) -
      reinterpret_cast<char*>(&_impl_.order_id_)) + sizeof(_impl_.price_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* OrderMessage::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // uint64 order_id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.order_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint64 user_id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          _impl_.user_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string symbol = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          auto str = _internal_mutable_symbol();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "OrderMessage.symbol"));
        } else
          goto handle_unusual;
        continue;
      // .Direction side = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 32)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_side(static_cast<::Direction>(val));
        } else
          goto handle_unusual;
        continue;
      // uint64 transaction_time = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 40)) {
          _impl_.transaction_time_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // float order_quantity = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 53)) {
          _impl_.order_quantity_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      // float price = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 61)) {
          _impl_.price_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* OrderMessage::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:OrderMessage)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // uint64 order_id = 1;
  if (this->_internal_order_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt64ToArray(1, this->_internal_order_id(), target);
  }

  // uint64 user_id = 2;
  if (this->_internal_user_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt64ToArray(2, this->_internal_user_id(), target);
  }

  // string symbol = 3;
  if (!this->_internal_symbol().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_symbol().data(), static_cast<int>(this->_internal_symbol().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "OrderMessage.symbol");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_symbol(), target);
  }

  // .Direction side = 4;
  if (this->_internal_side() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      4, this->_internal_side(), target);
  }

  // uint64 transaction_time = 5;
  if (this->_internal_transaction_time() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt64ToArray(5, this->_internal_transaction_time(), target);
  }

  // float order_quantity = 6;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_order_quantity = this->_internal_order_quantity();
  uint32_t raw_order_quantity;
  memcpy(&raw_order_quantity, &tmp_order_quantity, sizeof(tmp_order_quantity));
  if (raw_order_quantity != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteFloatToArray(6, this->_internal_order_quantity(), target);
  }

  // float price = 7;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_price = this->_internal_price();
  uint32_t raw_price;
  memcpy(&raw_price, &tmp_price, sizeof(tmp_price));
  if (raw_price != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteFloatToArray(7, this->_internal_price(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:OrderMessage)
  return target;
}

size_t OrderMessage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:OrderMessage)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string symbol = 3;
  if (!this->_internal_symbol().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_symbol());
  }

  // uint64 order_id = 1;
  if (this->_internal_order_id() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(this->_internal_order_id());
  }

  // uint64 user_id = 2;
  if (this->_internal_user_id() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(this->_internal_user_id());
  }

  // uint64 transaction_time = 5;
  if (this->_internal_transaction_time() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(this->_internal_transaction_time());
  }

  // .Direction side = 4;
  if (this->_internal_side() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_side());
  }

  // float order_quantity = 6;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_order_quantity = this->_internal_order_quantity();
  uint32_t raw_order_quantity;
  memcpy(&raw_order_quantity, &tmp_order_quantity, sizeof(tmp_order_quantity));
  if (raw_order_quantity != 0) {
    total_size += 1 + 4;
  }

  // float price = 7;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_price = this->_internal_price();
  uint32_t raw_price;
  memcpy(&raw_price, &tmp_price, sizeof(tmp_price));
  if (raw_price != 0) {
    total_size += 1 + 4;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData OrderMessage::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    OrderMessage::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*OrderMessage::GetClassData() const { return &_class_data_; }


void OrderMessage::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<OrderMessage*>(&to_msg);
  auto& from = static_cast<const OrderMessage&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:OrderMessage)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_symbol().empty()) {
    _this->_internal_set_symbol(from._internal_symbol());
  }
  if (from._internal_order_id() != 0) {
    _this->_internal_set_order_id(from._internal_order_id());
  }
  if (from._internal_user_id() != 0) {
    _this->_internal_set_user_id(from._internal_user_id());
  }
  if (from._internal_transaction_time() != 0) {
    _this->_internal_set_transaction_time(from._internal_transaction_time());
  }
  if (from._internal_side() != 0) {
    _this->_internal_set_side(from._internal_side());
  }
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_order_quantity = from._internal_order_quantity();
  uint32_t raw_order_quantity;
  memcpy(&raw_order_quantity, &tmp_order_quantity, sizeof(tmp_order_quantity));
  if (raw_order_quantity != 0) {
    _this->_internal_set_order_quantity(from._internal_order_quantity());
  }
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_price = from._internal_price();
  uint32_t raw_price;
  memcpy(&raw_price, &tmp_price, sizeof(tmp_price));
  if (raw_price != 0) {
    _this->_internal_set_price(from._internal_price());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void OrderMessage::CopyFrom(const OrderMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:OrderMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool OrderMessage::IsInitialized() const {
  return true;
}

void OrderMessage::InternalSwap(OrderMessage* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.symbol_, lhs_arena,
      &other->_impl_.symbol_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(OrderMessage, _impl_.price_)
      + sizeof(OrderMessage::_impl_.price_)
      - PROTOBUF_FIELD_OFFSET(OrderMessage, _impl_.order_id_)>(
          reinterpret_cast<char*>(&_impl_.order_id_),
          reinterpret_cast<char*>(&other->_impl_.order_id_));
}

::PROTOBUF_NAMESPACE_ID::Metadata OrderMessage::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_protocols_2ftrademessage_2eproto_getter, &descriptor_table_protocols_2ftrademessage_2eproto_once,
      file_level_metadata_protocols_2ftrademessage_2eproto[0]);
}

// ===================================================================

class OrderResponse::_Internal {
 public:
};

OrderResponse::OrderResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:OrderResponse)
}
OrderResponse::OrderResponse(const OrderResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  OrderResponse* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.symbol_){}
    , decltype(_impl_.order_id_){}
    , decltype(_impl_.user_id_){}
    , decltype(_impl_.transaction_time_){}
    , decltype(_impl_.side_){}
    , decltype(_impl_.order_quantity_){}
    , decltype(_impl_.price_){}
    , decltype(_impl_.status_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.symbol_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.symbol_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_symbol().empty()) {
    _this->_impl_.symbol_.Set(from._internal_symbol(), 
      _this->GetArenaForAllocation());
  }
  ::memcpy(&_impl_.order_id_, &from._impl_.order_id_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.status_) -
    reinterpret_cast<char*>(&_impl_.order_id_)) + sizeof(_impl_.status_));
  // @@protoc_insertion_point(copy_constructor:OrderResponse)
}

inline void OrderResponse::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.symbol_){}
    , decltype(_impl_.order_id_){uint64_t{0u}}
    , decltype(_impl_.user_id_){uint64_t{0u}}
    , decltype(_impl_.transaction_time_){uint64_t{0u}}
    , decltype(_impl_.side_){0}
    , decltype(_impl_.order_quantity_){0}
    , decltype(_impl_.price_){0}
    , decltype(_impl_.status_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.symbol_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.symbol_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

OrderResponse::~OrderResponse() {
  // @@protoc_insertion_point(destructor:OrderResponse)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void OrderResponse::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.symbol_.Destroy();
}

void OrderResponse::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void OrderResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:OrderResponse)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.symbol_.ClearToEmpty();
  ::memset(&_impl_.order_id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.status_) -
      reinterpret_cast<char*>(&_impl_.order_id_)) + sizeof(_impl_.status_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* OrderResponse::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // uint64 order_id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.order_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint64 user_id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          _impl_.user_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string symbol = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          auto str = _internal_mutable_symbol();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "OrderResponse.symbol"));
        } else
          goto handle_unusual;
        continue;
      // .Direction side = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 32)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_side(static_cast<::Direction>(val));
        } else
          goto handle_unusual;
        continue;
      // uint64 transaction_time = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 40)) {
          _impl_.transaction_time_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // float order_quantity = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 53)) {
          _impl_.order_quantity_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      // float price = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 61)) {
          _impl_.price_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      // .OrderStatus status = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 64)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_status(static_cast<::OrderStatus>(val));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* OrderResponse::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:OrderResponse)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // uint64 order_id = 1;
  if (this->_internal_order_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt64ToArray(1, this->_internal_order_id(), target);
  }

  // uint64 user_id = 2;
  if (this->_internal_user_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt64ToArray(2, this->_internal_user_id(), target);
  }

  // string symbol = 3;
  if (!this->_internal_symbol().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_symbol().data(), static_cast<int>(this->_internal_symbol().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "OrderResponse.symbol");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_symbol(), target);
  }

  // .Direction side = 4;
  if (this->_internal_side() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      4, this->_internal_side(), target);
  }

  // uint64 transaction_time = 5;
  if (this->_internal_transaction_time() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt64ToArray(5, this->_internal_transaction_time(), target);
  }

  // float order_quantity = 6;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_order_quantity = this->_internal_order_quantity();
  uint32_t raw_order_quantity;
  memcpy(&raw_order_quantity, &tmp_order_quantity, sizeof(tmp_order_quantity));
  if (raw_order_quantity != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteFloatToArray(6, this->_internal_order_quantity(), target);
  }

  // float price = 7;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_price = this->_internal_price();
  uint32_t raw_price;
  memcpy(&raw_price, &tmp_price, sizeof(tmp_price));
  if (raw_price != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteFloatToArray(7, this->_internal_price(), target);
  }

  // .OrderStatus status = 8;
  if (this->_internal_status() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      8, this->_internal_status(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:OrderResponse)
  return target;
}

size_t OrderResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:OrderResponse)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string symbol = 3;
  if (!this->_internal_symbol().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_symbol());
  }

  // uint64 order_id = 1;
  if (this->_internal_order_id() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(this->_internal_order_id());
  }

  // uint64 user_id = 2;
  if (this->_internal_user_id() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(this->_internal_user_id());
  }

  // uint64 transaction_time = 5;
  if (this->_internal_transaction_time() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(this->_internal_transaction_time());
  }

  // .Direction side = 4;
  if (this->_internal_side() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_side());
  }

  // float order_quantity = 6;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_order_quantity = this->_internal_order_quantity();
  uint32_t raw_order_quantity;
  memcpy(&raw_order_quantity, &tmp_order_quantity, sizeof(tmp_order_quantity));
  if (raw_order_quantity != 0) {
    total_size += 1 + 4;
  }

  // float price = 7;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_price = this->_internal_price();
  uint32_t raw_price;
  memcpy(&raw_price, &tmp_price, sizeof(tmp_price));
  if (raw_price != 0) {
    total_size += 1 + 4;
  }

  // .OrderStatus status = 8;
  if (this->_internal_status() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_status());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData OrderResponse::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    OrderResponse::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*OrderResponse::GetClassData() const { return &_class_data_; }


void OrderResponse::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<OrderResponse*>(&to_msg);
  auto& from = static_cast<const OrderResponse&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:OrderResponse)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_symbol().empty()) {
    _this->_internal_set_symbol(from._internal_symbol());
  }
  if (from._internal_order_id() != 0) {
    _this->_internal_set_order_id(from._internal_order_id());
  }
  if (from._internal_user_id() != 0) {
    _this->_internal_set_user_id(from._internal_user_id());
  }
  if (from._internal_transaction_time() != 0) {
    _this->_internal_set_transaction_time(from._internal_transaction_time());
  }
  if (from._internal_side() != 0) {
    _this->_internal_set_side(from._internal_side());
  }
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_order_quantity = from._internal_order_quantity();
  uint32_t raw_order_quantity;
  memcpy(&raw_order_quantity, &tmp_order_quantity, sizeof(tmp_order_quantity));
  if (raw_order_quantity != 0) {
    _this->_internal_set_order_quantity(from._internal_order_quantity());
  }
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_price = from._internal_price();
  uint32_t raw_price;
  memcpy(&raw_price, &tmp_price, sizeof(tmp_price));
  if (raw_price != 0) {
    _this->_internal_set_price(from._internal_price());
  }
  if (from._internal_status() != 0) {
    _this->_internal_set_status(from._internal_status());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void OrderResponse::CopyFrom(const OrderResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:OrderResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool OrderResponse::IsInitialized() const {
  return true;
}

void OrderResponse::InternalSwap(OrderResponse* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.symbol_, lhs_arena,
      &other->_impl_.symbol_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(OrderResponse, _impl_.status_)
      + sizeof(OrderResponse::_impl_.status_)
      - PROTOBUF_FIELD_OFFSET(OrderResponse, _impl_.order_id_)>(
          reinterpret_cast<char*>(&_impl_.order_id_),
          reinterpret_cast<char*>(&other->_impl_.order_id_));
}

::PROTOBUF_NAMESPACE_ID::Metadata OrderResponse::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_protocols_2ftrademessage_2eproto_getter, &descriptor_table_protocols_2ftrademessage_2eproto_once,
      file_level_metadata_protocols_2ftrademessage_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::OrderMessage*
Arena::CreateMaybeMessage< ::OrderMessage >(Arena* arena) {
  return Arena::CreateMessageInternal< ::OrderMessage >(arena);
}
template<> PROTOBUF_NOINLINE ::OrderResponse*
Arena::CreateMaybeMessage< ::OrderResponse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::OrderResponse >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
