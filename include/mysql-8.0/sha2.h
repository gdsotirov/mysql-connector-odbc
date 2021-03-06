// Copyright (c) 2007, 2018, Oracle and/or its affiliates. All rights reserved. 
// 
// This program is free software; you can redistribute it and/or modify 
// it under the terms of the GNU General Public License, version 2.0, as 
// published by the Free Software Foundation. 
// 
// This program is also distributed with certain software (including 
// but not limited to OpenSSL) that is licensed under separate terms, 
// as designated in a particular file or component or in included license 
// documentation. The authors of MySQL hereby grant you an 
// additional permission to link the program and your derivative works 
// with the separately licensed software that they have included with 
// MySQL. 
// 
// Without limiting anything contained in the foregoing, this file, 
// which is part of MySQL Server, is also subject to the 
// Universal FOSS Exception, version 1.0, a copy of which can be found at 
// http://oss.oracle.com/licenses/universal-foss-exception. 
// 
// This program is distributed in the hope that it will be useful, but 
// WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
// See the GNU General Public License, version 2.0, for more details. 
// 
// You should have received a copy of the GNU General Public License 
// along with this program; if not, write to the Free Software Foundation, Inc., 
// 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA 

#ifndef included_sha2_h
#define included_sha2_h

/**
  @file include/sha2.h
*/

#if defined(HAVE_OPENSSL)

#include <openssl/evp.h>
#include <stddef.h>

#if !defined(HAVE_WOLFSSL)
#include <openssl/sha.h>
#endif  // !defined(HAVE_WOLFSSL)

#if defined(HAVE_WOLFSSL) && defined(__cplusplus)
extern "C" {
#endif  // defined(HAVE_WOLFSSL) && defined(__cplusplus)

#define GEN_OPENSSL_EVP_SHA2_BRIDGE(size)                      \
  unsigned char *SHA_EVP##size(const unsigned char *input_ptr, \
                               size_t input_length,            \
                               char unsigned *output_ptr);
GEN_OPENSSL_EVP_SHA2_BRIDGE(512)
GEN_OPENSSL_EVP_SHA2_BRIDGE(384)
GEN_OPENSSL_EVP_SHA2_BRIDGE(256)
GEN_OPENSSL_EVP_SHA2_BRIDGE(224)
#undef GEN_OPENSSL_EVP_SHA2_BRIDGE

#if defined(HAVE_WOLFSSL) && defined(__cplusplus)
}
#endif  // defined(HAVE_WOLFSSL) && defined(__cplusplus)

#endif /* HAVE_OPENSSL */
#endif /* included_sha2_h */
