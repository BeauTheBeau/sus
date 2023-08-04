#include <array>
#include <cmath>
#include <limits>
#include <cstdio>

constexpr double sqrt_cre(double x, double curr, double prev) {
    return (curr == prev) ? curr : sqrt_cre(x, 0.5 * (curr + x / curr), curr);
}

constexpr double sqrt(double x) {
    return ((x >= 0) && (x < std::numeric_limits<double>::infinity()) ? sqrt_cre(x, x, 0) : std::numeric_limits<double>::quiet_NaN());
}

constexpr char get_pixel(std::size_t xs, std::size_t ys, std::size_t index) {
    const std::size_t xp = index % xs;
    const std::size_t yp = index / xs;
    const double x = 2 * static_cast<double>(xp) / static_cast<double>(xs);
    const double y = 3 * static_cast<double>(yp) / static_cast<double>(ys);

    const bool head  = (y <= 1.0) && ((-y + 1.0) <= sqrt(1.0 - std::pow(x - 1.0, 2.0)));
    const bool left  = (y >= 2.5) && ((-y + 2.5)  >= -sqrt(0.25 - std::pow(x - 0.5, 2.0)));
    const bool right = (y >= 2.5) && ((-y + 2.5)  >= -sqrt(0.25 - std::pow(x - 1.5, 2.0)));
    const bool body  = (std::abs(-y + 1.75) <= 0.75) && (std::abs(x - 1.0) <= 1.0);
    const bool visor = (x - 1.25) >= -sqrt(0.125 - std::pow(-y + 1.25, 2.0));

    return ((head || left || right || body) && !visor) ? 'A' : ' ';
}

constexpr std::size_t ratio = 1;
template <std::size_t W, std::size_t... I>
struct sus_core {
    static constexpr std::size_t w = W;
    static constexpr std::size_t h = w * ratio;
    static constexpr std::size_t size = w * h;
    static constexpr std::array<char, w * h> pixels{get_pixel(w, h, I)... };
};

template <std::size_t W, std::size_t... I>
constexpr auto sus_helper(std::index_sequence<I...>) {
    return sus_core<W, I...>{};
}

template <std::size_t W>
constexpr auto sus() {
    return sus_helper<W>(std::make_index_sequence<W * W * ratio>{});
}

int main() {
    constexpr auto result = sus<32>();

    for (std::size_t i = 0; i < result.pixels.size(); ++i) {
        putchar(result.pixels[i]);
        if ((i + 1) % result.w == 0) {
            putchar('\n');
        }
    }

    return 0;
}
