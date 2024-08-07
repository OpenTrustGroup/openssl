/*
 * Copyright 2017 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include "../testutil.h"
#include "output.h"

void cleanup_tests(void)
{
    cleanup_tests_asyncio();
    cleanup_tests_bntest();
    cleanup_tests_cipherbytes();
    cleanup_tests_cmsapi();
    cleanup_tests_crltest();
    cleanup_tests_dsa_no_digest_size();
    cleanup_tests_ec_internal();
    cleanup_tests_ecdsatest();
    cleanup_tests_ectest();
    cleanup_tests_recordlen();
    cleanup_tests_sysdefault();
    cleanup_tests_wpacket();

}
