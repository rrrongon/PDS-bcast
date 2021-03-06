/* Copyright (c) 2001-2022, The Ohio State University. All rights
 * reserved.
 *
 * This file is part of the MVAPICH2 software package developed by the
 * team members of The Ohio State University's Network-Based Computing
 * Laboratory (NBCL), headed by Professor Dhabaleswar K. (DK) Panda.
 *
 * For detailed copyright and licensing information, please refer to the
 * copyright file COPYRIGHT in the top level MVAPICH2 directory.
 *
 */

#include <mpichconf.h>

#ifdef CR_AGGRE

#include "genhash.h"

static unsigned long rabintab[256] = {
    0x0000000000000000ULL,
    0xee855d67e609d827ULL,
    0x338fe7a82a1a6869ULL,
    0xdd0abacfcc13b04eULL,
    0x671fcf505434d0d2ULL,
    0x899a9237b23d08f5ULL,
    0x549028f87e2eb8bbULL,
    0xba15759f9827609cULL,
    0xce3f9ea0a869a1a4ULL,
    0x20bac3c74e607983ULL,
    0xfdb079088273c9cdULL,
    0x1335246f647a11eaULL,
    0xa92051f0fc5d7176ULL,
    0x47a50c971a54a951ULL,
    0x9aafb658d647191fULL,
    0x742aeb3f304ec138ULL,
    0x72fa6026b6da9b6fULL,
    0x9c7f3d4150d34348ULL,
    0x4175878e9cc0f306ULL,
    0xaff0dae97ac92b21ULL,
    0x15e5af76e2ee4bbdULL,
    0xfb60f21104e7939aULL,
    0x266a48dec8f423d4ULL,
    0xc8ef15b92efdfbf3ULL,
    0xbcc5fe861eb33acbULL,
    0x5240a3e1f8bae2ecULL,
    0x8f4a192e34a952a2ULL,
    0x61cf4449d2a08a85ULL,
    0xdbda31d64a87ea19ULL,
    0x355f6cb1ac8e323eULL,
    0xe855d67e609d8270ULL,
    0x06d08b1986945a57ULL,
    0xe5f4c04d6db536deULL,
    0x0b719d2a8bbceef9ULL,
    0xd67b27e547af5eb7ULL,
    0x38fe7a82a1a68690ULL,
    0x82eb0f1d3981e60cULL,
    0x6c6e527adf883e2bULL,
    0xb164e8b5139b8e65ULL,
    0x5fe1b5d2f5925642ULL,
    0x2bcb5eedc5dc977aULL,
    0xc54e038a23d54f5dULL,
    0x1844b945efc6ff13ULL,
    0xf6c1e42209cf2734ULL,
    0x4cd491bd91e847a8ULL,
    0xa251ccda77e19f8fULL,
    0x7f5b7615bbf22fc1ULL,
    0x91de2b725dfbf7e6ULL,
    0x970ea06bdb6fadb1ULL,
    0x798bfd0c3d667596ULL,
    0xa48147c3f175c5d8ULL,
    0x4a041aa4177c1dffULL,
    0xf0116f3b8f5b7d63ULL,
    0x1e94325c6952a544ULL,
    0xc39e8893a541150aULL,
    0x2d1bd5f44348cd2dULL,
    0x59313ecb73060c15ULL,
    0xb7b463ac950fd432ULL,
    0x6abed963591c647cULL,
    0x843b8404bf15bc5bULL,
    0x3e2ef19b2732dcc7ULL,
    0xd0abacfcc13b04e0ULL,
    0x0da116330d28b4aeULL,
    0xe3244b54eb216c89ULL,
    0x256cddfd3d63b59bULL,
    0xcbe9809adb6a6dbcULL,
    0x16e33a551779ddf2ULL,
    0xf8666732f17005d5ULL,
    0x427312ad69576549ULL,
    0xacf64fca8f5ebd6eULL,
    0x71fcf505434d0d20ULL,
    0x9f79a862a544d507ULL,
    0xeb53435d950a143fULL,
    0x05d61e3a7303cc18ULL,
    0xd8dca4f5bf107c56ULL,
    0x3659f9925919a471ULL,
    0x8c4c8c0dc13ec4edULL,
    0x62c9d16a27371ccaULL,
    0xbfc36ba5eb24ac84ULL,
    0x514636c20d2d74a3ULL,
    0x5796bddb8bb92ef4ULL,
    0xb913e0bc6db0f6d3ULL,
    0x64195a73a1a3469dULL,
    0x8a9c071447aa9ebaULL,
    0x3089728bdf8dfe26ULL,
    0xde0c2fec39842601ULL,
    0x03069523f597964fULL,
    0xed83c844139e4e68ULL,
    0x99a9237b23d08f50ULL,
    0x772c7e1cc5d95777ULL,
    0xaa26c4d309cae739ULL,
    0x44a399b4efc33f1eULL,
    0xfeb6ec2b77e45f82ULL,
    0x1033b14c91ed87a5ULL,
    0xcd390b835dfe37ebULL,
    0x23bc56e4bbf7efccULL,
    0xc0981db050d68345ULL,
    0x2e1d40d7b6df5b62ULL,
    0xf317fa187acceb2cULL,
    0x1d92a77f9cc5330bULL,
    0xa787d2e004e25397ULL,
    0x49028f87e2eb8bb0ULL,
    0x940835482ef83bfeULL,
    0x7a8d682fc8f1e3d9ULL,
    0x0ea78310f8bf22e1ULL,
    0xe022de771eb6fac6ULL,
    0x3d2864b8d2a54a88ULL,
    0xd3ad39df34ac92afULL,
    0x69b84c40ac8bf233ULL,
    0x873d11274a822a14ULL,
    0x5a37abe886919a5aULL,
    0xb4b2f68f6098427dULL,
    0xb2627d96e60c182aULL,
    0x5ce720f10005c00dULL,
    0x81ed9a3ecc167043ULL,
    0x6f68c7592a1fa864ULL,
    0xd57db2c6b238c8f8ULL,
    0x3bf8efa1543110dfULL,
    0xe6f2556e9822a091ULL,
    0x087708097e2b78b6ULL,
    0x7c5de3364e65b98eULL,
    0x92d8be51a86c61a9ULL,
    0x4fd2049e647fd1e7ULL,
    0xa15759f9827609c0ULL,
    0x1b422c661a51695cULL,
    0xf5c77101fc58b17bULL,
    0x28cdcbce304b0135ULL,
    0xc64896a9d642d912ULL,
    0x4ad9bbfa7ac76b36ULL,
    0xa45ce69d9cceb311ULL,
    0x79565c5250dd035fULL,
    0x97d30135b6d4db78ULL,
    0x2dc674aa2ef3bbe4ULL,
    0xc34329cdc8fa63c3ULL,
    0x1e49930204e9d38dULL,
    0xf0ccce65e2e00baaULL,
    0x84e6255ad2aeca92ULL,
    0x6a63783d34a712b5ULL,
    0xb769c2f2f8b4a2fbULL,
    0x59ec9f951ebd7adcULL,
    0xe3f9ea0a869a1a40ULL,
    0x0d7cb76d6093c267ULL,
    0xd0760da2ac807229ULL,
    0x3ef350c54a89aa0eULL,
    0x3823dbdccc1df059ULL,
    0xd6a686bb2a14287eULL,
    0x0bac3c74e6079830ULL,
    0xe5296113000e4017ULL,
    0x5f3c148c9829208bULL,
    0xb1b949eb7e20f8acULL,
    0x6cb3f324b23348e2ULL,
    0x8236ae43543a90c5ULL,
    0xf61c457c647451fdULL,
    0x1899181b827d89daULL,
    0xc593a2d44e6e3994ULL,
    0x2b16ffb3a867e1b3ULL,
    0x91038a2c3040812fULL,
    0x7f86d74bd6495908ULL,
    0xa28c6d841a5ae946ULL,
    0x4c0930e3fc533161ULL,
    0xaf2d7bb717725de8ULL,
    0x41a826d0f17b85cfULL,
    0x9ca29c1f3d683581ULL,
    0x7227c178db61eda6ULL,
    0xc832b4e743468d3aULL,
    0x26b7e980a54f551dULL,
    0xfbbd534f695ce553ULL,
    0x15380e288f553d74ULL,
    0x6112e517bf1bfc4cULL,
    0x8f97b8705912246bULL,
    0x529d02bf95019425ULL,
    0xbc185fd873084c02ULL,
    0x060d2a47eb2f2c9eULL,
    0xe88877200d26f4b9ULL,
    0x3582cdefc13544f7ULL,
    0xdb079088273c9cd0ULL,
    0xddd71b91a1a8c687ULL,
    0x335246f647a11ea0ULL,
    0xee58fc398bb2aeeeULL,
    0x00dda15e6dbb76c9ULL,
    0xbac8d4c1f59c1655ULL,
    0x544d89a61395ce72ULL,
    0x89473369df867e3cULL,
    0x67c26e0e398fa61bULL,
    0x13e8853109c16723ULL,
    0xfd6dd856efc8bf04ULL,
    0x2067629923db0f4aULL,
    0xcee23ffec5d2d76dULL,
    0x74f74a615df5b7f1ULL,
    0x9a721706bbfc6fd6ULL,
    0x4778adc977efdf98ULL,
    0xa9fdf0ae91e607bfULL,
    0x6fb5660747a4deadULL,
    0x81303b60a1ad068aULL,
    0x5c3a81af6dbeb6c4ULL,
    0xb2bfdcc88bb76ee3ULL,
    0x08aaa95713900e7fULL,
    0xe62ff430f599d658ULL,
    0x3b254eff398a6616ULL,
    0xd5a01398df83be31ULL,
    0xa18af8a7efcd7f09ULL,
    0x4f0fa5c009c4a72eULL,
    0x92051f0fc5d71760ULL,
    0x7c80426823decf47ULL,
    0xc69537f7bbf9afdbULL,
    0x28106a905df077fcULL,
    0xf51ad05f91e3c7b2ULL,
    0x1b9f8d3877ea1f95ULL,
    0x1d4f0621f17e45c2ULL,
    0xf3ca5b4617779de5ULL,
    0x2ec0e189db642dabULL,
    0xc045bcee3d6df58cULL,
    0x7a50c971a54a9510ULL,
    0x94d5941643434d37ULL,
    0x49df2ed98f50fd79ULL,
    0xa75a73be6959255eULL,
    0xd37098815917e466ULL,
    0x3df5c5e6bf1e3c41ULL,
    0xe0ff7f29730d8c0fULL,
    0x0e7a224e95045428ULL,
    0xb46f57d10d2334b4ULL,
    0x5aea0ab6eb2aec93ULL,
    0x87e0b07927395cddULL,
    0x6965ed1ec13084faULL,
    0x8a41a64a2a11e873ULL,
    0x64c4fb2dcc183054ULL,
    0xb9ce41e2000b801aULL,
    0x574b1c85e602583dULL,
    0xed5e691a7e2538a1ULL,
    0x03db347d982ce086ULL,
    0xded18eb2543f50c8ULL,
    0x3054d3d5b23688efULL,
    0x447e38ea827849d7ULL,
    0xaafb658d647191f0ULL,
    0x77f1df42a86221beULL,
    0x997482254e6bf999ULL,
    0x2361f7bad64c9905ULL,
    0xcde4aadd30454122ULL,
    0x10ee1012fc56f16cULL,
    0xfe6b4d751a5f294bULL,
    0xf8bbc66c9ccb731cULL,
    0x163e9b0b7ac2ab3bULL,
    0xcb3421c4b6d11b75ULL,
    0x25b17ca350d8c352ULL,
    0x9fa4093cc8ffa3ceULL,
    0x7121545b2ef67be9ULL,
    0xac2bee94e2e5cba7ULL,
    0x42aeb3f304ec1380ULL,
    0x368458cc34a2d2b8ULL,
    0xd80105abd2ab0a9fULL,
    0x050bbf641eb8bad1ULL,
    0xeb8ee203f8b162f6ULL,
    0x519b979c6096026aULL,
    0xbf1ecafb869fda4dULL,
    0x621470344a8c6a03ULL,
    0x8c912d53ac85b224ULL
};

unsigned long generic_hash(const void *p, int n, int result_bits)
{
    unsigned long h = rabinhash(p, n);
    unsigned long m = 1LL << result_bits;

    h &= (m - 1);               //64-result_bits);
    return h;
}

unsigned long rabinhash(const void *p, int n)
{
    unsigned int x;
    unsigned long h;
    unsigned char *d, *e;

    h = 1;
    d = (unsigned char *) p;
    e = d + n;
    while (d < e) {
        x = h >> 56;
        h <<= 8;
        h |= *d++;
        h ^= rabintab[x];
    }
    return h;
}

#endif
