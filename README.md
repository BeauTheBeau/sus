# sus

"sus" is a C++ program that generates a pixel art representation of an
[Among Us](https://www.innersloth.com/gameAmongUs.php) character using ASCII characters. The character is made up
of simple geometric shapes.

## Usage

```bash
# 1. Clone the repository:
git clone https://github.com/your-username/sus.git
cd sus

# 2. Compile and run the program:
g++ -Wall -std=c++20 sus.cpp -o sus
./sus
```

## Customization
You can customize the width of the character representation by modifying the W parameter in the sus() function call
inside the main function. The default width is set to 30, but you can change it to any positive integer value to adjust
the size of the output.

## Dependencies
C++20 standard library

## License

This project is licenced under the MIT license. See the [LICENCE](LICENCE) file for details.

