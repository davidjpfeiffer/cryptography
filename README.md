# Cryptography
A collection of cryptographic ciphers

### Getting Started

 - Clone the repository
 - Run the `build` script
 - Navigate to the newly generated `/builds` directory
 - Use the ciphers to encrypt and decrypt messages
 
 ### How It Works

The ciphers are written in C++ and compiled to executables using a batch file. Each cipher accepts one optional command line argument, which is the key used to encrypt and decrypt. If no key is provided a default key is used. Upon execution each cipher takes in the message to be encrypted via standard input. This allows the ciphers to be piped togehter.

### Tips and Tricks

The build script automatically generates the `message.txt` file to be used as example input for the ciphers. You can pipe the contents of this file to the ciphers using the `type` command, as seen below.

![pipe example](https://github.com/davidjpfeiffer/cryptography/blob/master/resources/pipe-example.png)
