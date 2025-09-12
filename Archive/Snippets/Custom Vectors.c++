template<class T> auto V(const T& value, int size) {
        return vector<T>(size, value);
}

template<class T, class... D> auto V(const T& value, int size, D... w) {
        auto W = V(value, w...); 
        return vector<decltype(W)>(size, W);
}