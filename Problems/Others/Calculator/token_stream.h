#ifndef ALGO_TOKEN_STREAM_H
#define ALGO_TOKEN_STREAM_H

#include <istream>

#include "parser.h"

namespace algo {

namespace problems {

/**
 * @brief   TokenStream : this is the class that parse the input stream for the desktop calculator
 */
class TokenStream {
 public:
  TokenStream(std::istream& ip) : ip_{ip} {}

  Token get();          // read and return the next token
  Token& current();     // most recently read token
 private:
  std::istream&   ip_;
  Token           cur_token_{Kind::end};
};

} // namespace algo::problems

} // namespace algo

#endif //ALGO_TOKEN_STREAM_H
