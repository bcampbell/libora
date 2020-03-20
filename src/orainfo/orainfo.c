/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * Redistribution and use in source and binary forms, with or without modification, are
 * permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of
 *    conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list
 *    of conditions and the following disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY LIBORA DEVELOPERS ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL LIBORA DEVELOPERS OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * The views and conclusions contained in the software and documentation are those of the
 * authors and should not be interpreted as representing official policies, either expressed
 * or implied, of libora developers.
 */

//#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ora.h>


// Dumps out information & structure of an ora file to stdout.

int main( int argc, char** argv) { 
    ORA ora_in;
    int i;
    long timer, total, read, write;

    if (argc < 2) {
        fprintf(stderr,"Enter a file name!\n");
        return -1;
    }

    int ret_code = 0;
    for (int i=1; i<argc; ++i) {
        ORA ora_in;
        if (ora_open(argv[i], ORA_FILE_READ, &ora_in) != ORA_OK) {
            fprintf(stderr, "couldn't open %s\n", argv[i]);
            ret_code = -1;
            break;
        }
        // TODO: should write the dump function using public API, but right
        // now we can't everything needed. So it's a library function for now.
        ora_dump(ora_in);
        ora_close(ora_in);
    }
    return ret_code;
}

