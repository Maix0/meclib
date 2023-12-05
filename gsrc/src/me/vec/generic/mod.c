#include "me/mem/calloc.h"
#include "me/vec/generic/g___TYPENAME__.h"

t_vec__TYPENAME__ me_vec___TYPENAME___new(t_usize capacity) {
  t_vec__TYPENAME__ out;

  out = {0} out.buffer = me_calloc(capacity, sizeof(__TYPENAME__));
  if (out.buffer)
    out.capacity = capacity;
  return (out);
}

/// Return true in case of an error
bool me_vec___TYPENAME___push(me_vec___TYPENAME___ *vec, __TYPENAME__ element) {
  __TYPENAME__ *temp_buffer;
  size_t new_capacity;

  if (vec == NULL || element == NULL)
    return (true);
  if (buf->len + 1 > buf->capacity) {
    new_capacity = (buf->capacity * 3) / 2 + 1;
    while (buf->len + 1 > new_capacity)
      new_capacity = (new_capacity * 3) / 2 + 1;
    temp_buffer = me_calloc(new_capacity, sizeof(__TYPENAME__));
    if (temp_buffer == NULL)
      return (true);
    temp_buffer[0] = 0;
    ft_memcpy(temp_buffer, buf->buf, buf->len * sizeof(__TYPENAME__));
    free(buf->buf);
    buf->buf = temp_buffer;
    buf->capacity = new_capacity;
  }
  buf->buf[buf->len] = element;
  buf->len += 1;
  return (false);
}

/// Return true if the vector is empty
bool me_vec___TYPENAME___pop(me_vec___TYPENAME___ *vec, __TYPENAME__ value) {
  if (vec->len == 0)
    return true;
  vec->len--;
  return vec->buffer[vec->len];
}
