# A brief Note about How to install simplescalar on Unbuntu

## Environment

simplescalar v3.0e ->  
Win10 VMware Ubuntu 16.04 with Linux 4.4.0 x86_64

## Install Simplescalar

### Environment variables and modules needed

- gcc-2.7.2.3.ss.tar.gz
- simplesim-3v0e.tgz
- simpletools-2v0.tgz
- simpleutils-990811.tar.gz
- patch needed: ar & ranlib

These files can be easily found in the Internet.  

Define environmen variables:

```
export IDIR=~/YOUR_PATH/simplescalar/
export HOST=i686-pc-linux
export TARGET=sslittle-na-sstrix
```
Intall essencial modules:
```
sudo apt-get install build-essential
sudo apt-get install flex
sudo apt-get install bison
sudo apt-get gcc-multilib
sudo apt-get g++multilib
```
### Install Simpletools
```
cd $IDIR
tar xvfz simpletools-2v0.tgz
rm -rf gcc-2.6.3
```
Use `rm` to delete gcc, we need gcc-2.7.2.3 instead.

### Install Simpleutils
```
cd $IDIR
tar xvfz simpleutils-990811.tar.gz
cd simpleutils-990811
```
Find `ldlex.l` in `$IDIR/simpleutils-990811/ld/`
, change __yy_current_buffer__ to __YY_CURRENT_BUFFER__  
```
cd ..
./confing --host=$HOST --target=$TARGET --with-gnu-as --with-gnu-ld --prefix=$IDIR
make
make install
```

### Install Simplesim
```
cd $IDIR
tar xvfz simplesim-3v0e.tgz
cd simplesim-3.0
make config-pisa
make
```
If successful, message `my work is done here ... ` will show there.  
Find some tests in `$IDIR/simplesim-3.0/tests` with (such as) `./sim-safe tests/bin.little/test-llong` to start testing `test-llong`.  

### Install GCC Cross-compiling Environment
```
cd $IDIR
tar xvfz gcc-2.7.2.3.ss.tar.gz
cd gcc-2.7.2.3
./configure --host=$HOST --target=$TARGET --with-gnu-as --with-gnu-ld --prefix=$IDIR
```
To `make` successfully, a few bugs due to incompability should be fixed.

Firstly, use `chmod -R +w .` to get permission to rewrite files.

Secondly,  
- Find `Makefile`, add `-I/usr/include` to the end of line 130

- Find `protoize.c`, change __varargs.h__ to __stdarg.h__ in line 60

- Find `obstack.h`, change  
 __\*((void **)\_\_o->next_free)++__  
to __\*((void **)\_\_o->next_free++)__ in line 341

- Add patches with `cp`:
```
cp ./patched/sys/cdefs.h ../sslittle-na-sstrix/include/sys/cdefs.h
cp ../sslittle-na-sstrix/lib/libc.a ../lib/
cp ../sslittle-na-sstrix/lib/crt0.o ../lib/
```

Thirdly, start to `make`, use  
`make LANGUAGES="c c++" CFLAGS="-O" CC="gcc"`, but you will _maybe_ find some errors following:

- `insn-output.o`: Find `insn-ouput.c`, add `\` to the end of line 675, 750 and 823

- `sendmsg.c`: Find `objc/sendmsg.c`, add `#define STRUCT_VALUE 0` to line 35

- 'buffer overflow': Copy `ar` and `ranlib` (patches in `needed`) to `$IDIR/sslittle-na-sstrix/bin` and change their permission to execute with  
```
cd $IDIR/sslittle-na-sstrix/bin/
chmod +x ar ranlib
```

- `cxxmain.c`: Find it, and delete line 2978 and 2979

- `cc1plus.c`: This may due to the version of GCC. You may try degrading GCC to __v4.9__ with  
```
sudo apt-get install gcc-4.9
sudo apt-get install g++-4.9
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.9 20
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.9 20
```

_Note : during the attempts, you may use `make clean` after reinstall GCC. Maybe some errors will show again after that, just redo some steps above to the specific errors._

__Finally__ :), use
```
make enquire
../simplesim-3.0/sim-safe ./enquire -f >！ float.h-cross
make LANGUAGES="c c++" CFLAGS="-O" CC="gcc" install
```
to install compiler.

### Some tests
Under the `IDIR` directory, use `./sslittile-na-sstrix-gcc <test_file>` to compile.

You will find `.out` file in the same dir (default).

Use `sim-safe` to execute `.out`. You will finally see `** starting functional simlulation **...`.

And, of courese, `Hello World!`.

### Referance
[Install Simplescalar](http://www.cnblogs.com/blue163/p/4928394.html)  
[Reinstall GCC-4.9](http://www.cnblogs.com/darkknightzh/p/6194031.html)

_Transfered & Supplemented by Wenhan Shi, 2017.3_
