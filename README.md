# Cryptography

A collection of cryptographic ciphers

### Getting Started

 - Clone the repository
 - Run the `build` script
 - Navigate to the newly generated `/builds` directory
 - Use the ciphers to encrypt and decrypt messages
 
 ### How It Works

The ciphers are written in C++ and compiled to executables using a batch file. Each cipher accepts one optional command line argument, which is the key used to encrypt and decrypt. If no key is provided a default key is used. Each cipher accepts and returns input and output via standard input. This allows the ciphers to be piped togehter.

 ### List of Ciphers
 
 - [Shift Cipher](https://en.wikipedia.org/wiki/Caesar_cipher)
 - [Multiplicative Cipher](https://www.nku.edu/~christensen/section%206%20multiplicative%20ciphers.pdf)
 - [Affine Cipher](https://en.wikipedia.org/wiki/Affine_cipher)
 - [Hill Cipher](https://en.wikipedia.org/wiki/Hill_cipher)

### Tips and Tricks

The build script automatically generates a `message.txt` file to be used as example input for the ciphers. You can pipe the contents of this file to the ciphers using the `type` command, as seen below.

![pipe example](https://github.com/davidjpfeiffer/cryptography/blob/master/resources/pipe-example.png)

### Build and Test

There are two batch scripts, `build.bat` and `test.bat`, which are intended to make development of this project easier. The build script compiles the source code into executable files using MinGW and dumps the output into the `builds` directory.

The test script builds and runs a series of test on each cipher to ensure that the ciphers are providing basic encryption and decryption features. That is, that encrypting the plaintext obtains the ciphertext and decrypting the ciphertext obtains the plaintext, such that the plaintext is not equal to the ciphertext.

Note that both scripts use the [MinGW Compiler](http://www.mingw.org/wiki/InstallationHOWTOforMinGW) for compilation. To use these scripts you must have this dependency installed.

### License

GNU GENERAL PUBLIC LICENSE

ALL RIGHTS RESERVED
