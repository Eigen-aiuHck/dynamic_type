#include "dynamic_type.hpp"

/* redefined */
#define CREATE_MEMBER_FUNC_Database_type_base(TYPENAME)                        \
  bool constexpr Database_##TYPENAME::is_##TYPENAME() const noexcept {         \
    return true;                                                               \
  }                                                                            \
  TYPENAME const &Database_##TYPENAME::value_##TYPENAME() const & {            \
    return m_container_value;                                                  \
  }                                                                            \
  TYPENAME &Database_##TYPENAME::value_##TYPENAME() & {                        \
    return m_container_value;                                                  \
  }                                                                            \
  TYPENAME &&Database_##TYPENAME::value_##TYPENAME() && {                      \
    return std::move(m_container_value);                                       \
  }                                                                            \
  TYPENAME const &&Database_##TYPENAME::value_##TYPENAME() const && {          \
    return std::move(m_container_value);                                       \
  }                                                                            \
  TYPENAME constexpr Database_##TYPENAME::value_##TYPENAME##_or(TYPENAME &&v)  \
      const & {                                                                \
    return if_ret(is_##TYPENAME(), m_container_value, v);                      \
  }                                                                            \
  TYPENAME constexpr Database_##TYPENAME::value_##TYPENAME##_or(               \
      TYPENAME &&v) && {                                                       \
    return if_ret(is_##TYPENAME(), m_container_value, v);                      \
  }                                                                            \
  Database_typebase *&&Database_##TYPENAME::new__this_type() const {           \
    return std::move(new Database_##TYPENAME);                                 \
  }

namespace dataBase_type_entrys {

/*
 * it is entrys for default type.
 * if you wanna do adding, you must work in limit to /userEntryTypes.
 *
 * but, this except when you adding built-in type or populer std-lib type.
 */

// cstdint
CREATE_MEMBER_FUNC_Database_type_base(int8_t);
CREATE_MEMBER_FUNC_Database_type_base(vector_int8_t);
CREATE_MEMBER_FUNC_Database_type_base(int16_t);
CREATE_MEMBER_FUNC_Database_type_base(vector_int16_t);
CREATE_MEMBER_FUNC_Database_type_base(int32_t);
CREATE_MEMBER_FUNC_Database_type_base(vector_int32_t);
CREATE_MEMBER_FUNC_Database_type_base(uint8_t);
CREATE_MEMBER_FUNC_Database_type_base(vector_uint8_t);
CREATE_MEMBER_FUNC_Database_type_base(uint16_t);
CREATE_MEMBER_FUNC_Database_type_base(vector_uint16_t);
CREATE_MEMBER_FUNC_Database_type_base(uint32_t);
CREATE_MEMBER_FUNC_Database_type_base(vector_uint32_t);
// float
CREATE_MEMBER_FUNC_Database_type_base(float);
CREATE_MEMBER_FUNC_Database_type_base(vector_float);
// double
CREATE_MEMBER_FUNC_Database_type_base(double);
CREATE_MEMBER_FUNC_Database_type_base(vector_double);
// string
CREATE_MEMBER_FUNC_Database_type_base(string);
CREATE_MEMBER_FUNC_Database_type_base(vector_string);
//
} // namespace dataBase_type_entrys