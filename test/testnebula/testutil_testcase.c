/*
 * Copyright 2017 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include "testutil.h"
#include "testutil/tu_local.h"
int setup_tests(void)
{
   setup_tests_x509_check_cert_pkey("./testfile/servercert.pem","./testfile/serverkey.pem","cert", "ok");
   run_tests("setup_tests_x509_check_cert_pkey");
   clear_all_test();
   setup_tests_x509_check_cert_pkey("./testfile/servercert.pem","./testfile/wrongkey.pem","cert", "failed");
   run_tests("setup_tests_x509_check_cert_pkey");
   clear_all_test();
   setup_tests_x509_check_cert_pkey("./testfile/x509-check.csr","./testfile/x509-check-key.pem","req", "ok");
   run_tests("setup_tests_x509_check_cert_pkey");
   clear_all_test();
   setup_tests_x509_check_cert_pkey("./testfile/x509-check.csr","./testfile/wrongkey.pem","req", "failed");
   run_tests("setup_tests_x509_check_cert_pkey");
   clear_all_test();
   #if 1
   setup_tests_evp("./testfile/evpciph.txt");
   run_tests("setup_tests_evp-ciph");
   clear_all_test();
   setup_tests_evp("./testfile/evpdigest.txt");
   run_tests("setup_tests_evp-digest");
   clear_all_test();
   setup_tests_evp("./testfile/evpencod.txt");
   run_tests("setup_tests_evp-encode");
   clear_all_test();
   setup_tests_evp("./testfile/evpkdf.txt");
   run_tests("setup_tests_evp-kdf");
   clear_all_test();
   setup_tests_evp("./testfile/evppbe.txt");
   run_tests("setup_tests_evp-pbe");
   clear_all_test();
   setup_tests_evp("./testfile/evppkey_ecc.txt");
   run_tests("setup_tests_evp-pkeyecc");
   clear_all_test();
#endif

   setup_tests_asn1_encode();
   setup_tests_asn1_internal();
   setup_tests_asn1_string_table();
   setup_test_sasn1_time();
   setup_tests_asyncio();
   setup_tests_bad_dtls();
   setup_tests_bftest();
   setup_tests_bio_callback();
   setup_tests_bio_enc();
   setup_tests_bio_memleak();
   setup_tests_bntest();
   setup_tests_cast();
   setup_tests_chacha_internal();
   setup_tests_cipher_overhead();
   setup_tests_cipherbytes();
   setup_tests_cipherlist();
   setup_tests_ciphername();
   setup_tests_clienthellotest();
   setup_tests_cmsapi();
   setup_tests_constant_time();
   setup_tests_crltest();
   setup_tests_ctype_internal();
   setup_tests_curve448_internal();
   setup_tests_d2i("X509","decode", "./testfile/bad_cert.der");
   setup_tests_d2i("GENERAL_NAME","decode", "./testfile/bad_generalname.der");
   setup_tests_d2i("ASN1_ANY","BIO", "./testfile/bad_bio.der");
   setup_tests_d2i("ASN1_ANY","OK", "./testfile/high_tag.der");
   setup_tests_d2i("ASN1_INTEGER","decode", "./testfile/high_tag.der");
   setup_tests_d2i("ASN1_INTEGER","OK", "./testfile/int0.der");
   setup_tests_d2i("ASN1_INTEGER","OK", "./testfile/int1.der");
   setup_tests_d2i("ASN1_INTEGER","OK", "./testfile/intminus1.der");
   setup_tests_d2i("ASN1_ANY","OK", "./testfile/int0.der");
   setup_tests_d2i("ASN1_ANY","OK", "./testfile/int1.der");
   setup_tests_d2i("ASN1_ANY","OK", "./testfile/intminus1.der");
   setup_tests_d2i("ASN1_INTEGER","decode", "./testfile/bad-int-pad0.der");
   setup_tests_d2i("ASN1_INTEGER","decode", "./testfile/bad-int-padminus1.der");
   setup_tests_destest();
   setup_tests_dhtest();
   setup_tests_drbg_cavs();
   setup_tests_dsa_no_digest_size();
   setup_tests_dsatest();
   setup_tests_dtls_mtu();
   //setup_tests_dtlstest("./testfile/server.pem","./testfile/server.pem");
   setup_tests_ec_internal();
   setup_tests_ecdsatest();
   setup_tests_ectest();
   setup_tests_enginetest();
   setup_tests_errtest();
   setup_tests_exdatatest();
   setup_tests_exptest();
#if 0
   setup_tests_evp("./testfile/evpciph.txt");
   run_tests("setup_tests_evp-ciph");
   clear_all_test();
   setup_tests_evp("./testfile/evpdigest.txt");
   run_tests("setup_tests_evp-digest");
   clear_all_test();
   setup_tests_evp("./testfile/evpencod.txt");
   run_tests("setup_tests_evp-encode");
   clear_all_test();
   setup_tests_evp("./testfile/evpkdf.txt");
   run_tests("setup_tests_evp-kdf");
   clear_all_test();
   setup_tests_evp("./testfile/evppbe.txt");
   run_tests("setup_tests_evp-pbe");
   clear_all_test();
   setup_tests_evp("./testfile/evppkey_ecc.txt");
   run_tests("setup_tests_evp-pkeyecc");
   clear_all_test();
#endif
   setup_tests_fatalerrtest("./testfile/server.pem","./testfile/server.pem");
   setup_tests_gmdifftest();
   setup_tests_hmactest();
   setup_tests_ideatest();
   setup_tests_igetest();
   setup_tests_lhash_test();
   setup_tests_md2test();
   setup_tests_mdc2_internal();
   setup_tests_mdc2test();
   setup_tests_modes_internal();
   setup_tests_ocspapitest("./testfile/cert.pem","./testfile/key.pem");
   setup_tests_packettest();
   setup_tests_pbelutest();
   setup_tests_pemtest();
   setup_tests_pkey_meth_kdf();
   setup_tests_pkey_meth();
   setup_tests_poly1305_internal();  
   setup_tests_rc2test();
   setup_tests_rc4test();
   setup_tests_rc5test();
   setup_tests_rdrand_sanity();
   setup_tests_recordlen("./testfile/server.pem","./testfile/server.pem");
   setup_tests_rsa_mp();
   setup_tests_rsa_test();
   setup_tests_sanity();
   setup_tests_secmem();
   setup_tests_servername("./testfile/server.pem","./testfile/server.pem");
   setup_tests_siphash_internal();
   setup_tests_sm2_internal();
   setup_tests_sm4_internal();
   setup_tests_srptest();
   setup_tests_stack();
   setup_tests_threadstest();
   setup_tests_time_offset();
   setup_tests_tls13ccstest("./testfile/server.pem","./testfile/server.pem");
   setup_tests_tls13encryptiontest();
   setup_tests_v3ext("./testfile/pathlen.pem");
   setup_tests_v3nametest();
   setup_tests_verify_extra("./testfile/roots.pem","./testfile/untrusted.pem","./testfile/bad.pem");
   setup_tests_wpacket(); 
   setup_tests_x509_dup_cert();
   setup_tests_x509_internal();
   setup_tests_x509_time();
   setup_tests_x509aux("./testfile/roots.pem");
   setup_tests_x509aux("./testfile/root+anyEKU.pem");
   setup_tests_x509aux("./testfile/root-anyEKU.pem");
   setup_tests_x509aux("./testfile/root-cert.pem");
 
   return 1;
}
