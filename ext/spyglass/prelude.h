#ifndef SPYGLASS_PRELUDE_H_
#define SPYGLASS_PRELUDE_H_

#ifndef Data_Set_Struct
#define Data_Set_Struct(obj,ptr) do {\
  Check_Type(obj, T_DATA); \
  DATA_PTR(obj) = ptr; \
} while (0);
#endif

#define SG_GEN_GET_OBJECT_FUNCTION(func, type) \
  inline type *func(VALUE obj) { \
    type *ptr; \
    Data_Get_Struct(obj, type, ptr); \
    return ptr; \
  }

#define SG_OPTION(opts, type, key, default, expr) \
  type key = default; \
  if(RTEST(opts)) { \
    Check_Type(opts, T_HASH); \
    do { \
      VALUE option; \
      option = rb_hash_aref(opts, rb_str_new2(#key)); \
      if(!RTEST(option)) \
        option = rb_hash_aref(opts, ID2SYM(rb_intern(#key))); \
      if(RTEST(option)) \
        key = expr(option); \
    } while(0); \
  }

#endif // SPYGLASS_PRELUDE_H_
