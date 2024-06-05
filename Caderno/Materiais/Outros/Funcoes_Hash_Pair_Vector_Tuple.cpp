// Definição de hash para pair
template <typename T1, typename T2>
struct std::hash<std::pair<T1, T2>> {
    std::size_t operator()(const std::pair<T1, T2>& p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1); // Combinação dos dois hashes
    }
};

// Definição de hash para vector
template <typename T>
struct std::hash<std::vector<T>> {
    std::size_t operator()(const std::vector<T>& v) const {
        std::size_t seed = 0;
        for (const auto& elem : v) {
            seed ^= std::hash<T>{}(elem) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};