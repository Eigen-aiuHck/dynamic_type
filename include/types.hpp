#pragma once
#include "extention_defines/ext_if"

#include <memory>
#include <stdexcept>
#include <stdint.h>
#include <string>
#include <unordered_map>
#include <vector>

// typename class
#define CREATE_MEMBER_FUNC_Database_type_base(TYPENAME)                        \
private:                                                                       \
  TYPENAME dummy_##TYPENAME;                                                   \
                                                                               \
public:                                                                        \
  virtual bool constexpr is_##TYPENAME() const noexcept { return false; }      \
  virtual TYPENAME const &value_##TYPENAME() const & {                         \
    throw std::runtime_error("exception : bad Database_type access");          \
    return dummy_##TYPENAME;                                                   \
  }                                                                            \
  virtual TYPENAME &value_##TYPENAME() & {                                     \
    throw std::runtime_error("exception : bad Database_type access");          \
    return dummy_##TYPENAME;                                                   \
  }                                                                            \
  virtual TYPENAME &&value_##TYPENAME() && {                                   \
    throw std::runtime_error("exception : bad Database_type access");          \
    return std::move(dummy_##TYPENAME);                                        \
  }                                                                            \
  virtual TYPENAME const &&value_##TYPENAME() const && {                       \
    throw std::runtime_error("exception : bad Database_type access");          \
    return std::move(dummy_##TYPENAME);                                        \
  }                                                                            \
  virtual TYPENAME constexpr value_##TYPENAME##_or(TYPENAME &&v) const & {     \
    return v;                                                                  \
  }                                                                            \
  virtual TYPENAME constexpr value_##TYPENAME##_or(TYPENAME &&v) && {          \
    return v;                                                                  \
  }

#define CREATE_CLASS__Database_type__entry(TYPENAME)                           \
  class Database_##TYPENAME : public Database_typebase {                       \
  private:                                                                     \
    using container_value_type = TYPENAME;                                     \
    static char constexpr const *const container_value_name = #TYPENAME;       \
    static inline value_identifier_type const container_value_identifier =     \
        std::make_pair(container_value_name, sizeof(TYPENAME));                \
    container_value_type m_container_value;                                    \
                                                                               \
  protected:                                                                   \
  public:                                                                      \
    Database_##TYPENAME() : Database_typebase(container_value_identifier) {}   \
    Database_##TYPENAME(container_value_type const &container_value)           \
        : Database_typebase(container_value_identifier),                       \
          m_container_value(container_value) {}                                \
    Database_##TYPENAME(Database_##TYPENAME const &) = default;                \
    Database_##TYPENAME(Database_##TYPENAME &&) = default;                     \
    bool constexpr operator==(Database_##TYPENAME const &v) const {            \
      return m_value_identifier == v.m_value_identifier;                       \
    }                                                                          \
                                                                               \
    /* override memvers */                                                     \
    virtual Database_typebase *&&new__this_type() const override;              \
    virtual constexpr bool is_##TYPENAME() const noexcept override;            \
    virtual TYPENAME const &value_##TYPENAME() const & override;               \
    virtual TYPENAME &value_##TYPENAME() & override;                           \
    virtual TYPENAME &&value_##TYPENAME() && override;                         \
    virtual TYPENAME const &&value_##TYPENAME() const && override;             \
    virtual TYPENAME constexpr value_##TYPENAME##_or(                          \
        TYPENAME &&v) const & override;                                        \
    virtual TYPENAME constexpr value_##TYPENAME##_or(TYPENAME &&v) &&          \
        override;                                                              \
  }

// stl container class
#define CREATE_CLASS__Database_dynamicArray__entry(TYPENAME)                   \
  class Database_##TYPENAME : public Database_typebase {                       \
  private:                                                                     \
    using container_value_type = TYPENAME;                                     \
    static char constexpr const *const container_value_name = #TYPENAME;       \
    static inline value_identifier_type const container_value_identifier =     \
        std::make_pair(container_value_name, 0);                               \
    container_value_type m_container_value;                                    \
                                                                               \
  protected:                                                                   \
  public:                                                                      \
    Database_##TYPENAME() : Database_typebase(container_value_identifier) {}   \
    Database_##TYPENAME(container_value_type const &container_value)           \
        : Database_typebase(container_value_identifier),                       \
          m_container_value(container_value) {}                                \
    Database_##TYPENAME(Database_##TYPENAME const &) = default;                \
    Database_##TYPENAME(Database_##TYPENAME &&) = default;                     \
    bool constexpr operator==(Database_##TYPENAME const &v) const {            \
      return m_value_identifier == v.m_value_identifier;                       \
    }                                                                          \
                                                                               \
    /* override memvers */                                                     \
    virtual Database_typebase *&&new__this_type() const override;              \
    virtual bool constexpr is_##TYPENAME() const noexcept override;            \
    virtual TYPENAME const &value_##TYPENAME() const & override;               \
    virtual TYPENAME &value_##TYPENAME() & override;                           \
    virtual TYPENAME &&value_##TYPENAME() && override;                         \
    virtual TYPENAME const &&value_##TYPENAME() const && override;             \
    virtual TYPENAME constexpr value_##TYPENAME##_or(                          \
        TYPENAME &&v) const & override;                                        \
    virtual TYPENAME constexpr value_##TYPENAME##_or(TYPENAME &&v) &&          \
        override;                                                              \
  }

namespace {
using vector_int8_t = std::vector<int8_t>;
using vector_int16_t = std::vector<int16_t>;
using vector_int32_t = std::vector<int32_t>;
using vector_uint8_t = std::vector<uint8_t>;
using vector_uint16_t = std::vector<uint16_t>;
using vector_uint32_t = std::vector<uint32_t>;
using vector_float = std::vector<float>;
using vector_double = std::vector<double>;
using string = std::string;
using vector_string = std::vector<std::string>;

} // namespace

class Database_typebase {
private:
protected:
  using value_identifier_type = std::pair<std::string, size_t>;
  // using container_value_type = typename;

  Database_typebase() = delete;
  Database_typebase(value_identifier_type const &identifier)
      : m_value_identifier(identifier) {}
  Database_typebase(Database_typebase const &) = default;
  Database_typebase(Database_typebase &&) = default;

  bool inline match_datatype(
      value_identifier_type const &expected_identifier) const noexcept {
    return (expected_identifier == m_value_identifier);
  }

public:
  value_identifier_type const m_value_identifier;

  bool constexpr operator==(Database_typebase const &v) const {
    return m_value_identifier == v.m_value_identifier;
  }

  // new override type.
  virtual Database_typebase *&&new__this_type() const = 0;

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
};

namespace dataBase_type_entrys {

// cstdint
CREATE_CLASS__Database_type__entry(int8_t);
CREATE_CLASS__Database_dynamicArray__entry(vector_int8_t);
CREATE_CLASS__Database_type__entry(int16_t);
CREATE_CLASS__Database_dynamicArray__entry(vector_int16_t);
CREATE_CLASS__Database_type__entry(int32_t);
CREATE_CLASS__Database_dynamicArray__entry(vector_int32_t);
CREATE_CLASS__Database_type__entry(uint8_t);
CREATE_CLASS__Database_dynamicArray__entry(vector_uint8_t);
CREATE_CLASS__Database_type__entry(uint16_t);
CREATE_CLASS__Database_dynamicArray__entry(vector_uint16_t);
CREATE_CLASS__Database_type__entry(uint32_t);
CREATE_CLASS__Database_dynamicArray__entry(vector_uint32_t);
// float
CREATE_CLASS__Database_type__entry(float);
CREATE_CLASS__Database_dynamicArray__entry(vector_float);
// double
CREATE_CLASS__Database_type__entry(double);
CREATE_CLASS__Database_dynamicArray__entry(vector_double);
// string
CREATE_CLASS__Database_type__entry(string);
CREATE_CLASS__Database_dynamicArray__entry(vector_string);

// including user types
#include "./entry_userClass/main.entry"
} // namespace dataBase_type_entrys