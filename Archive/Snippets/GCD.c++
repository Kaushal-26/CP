auto gcd2 = []<std::integral T>(T a, T b) -> T {
        while (b) a = std::exchange(b, a % b);
        return std::abs(a);
};