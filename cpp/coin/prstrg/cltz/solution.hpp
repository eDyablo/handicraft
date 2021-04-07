namespace coin {
  namespace prstrg {
    template <typename T>
    auto next(T current) {
      if (current % 2 == 0) {
        return current / 2;
      } else {
        return 3 * current + 1;
      }
    }

    template <typename T>
    size_t collatz(T number) {
      auto count = size_t{0};
      while (number != 1) {
        ++count;
        number = next(number);
      }
      return count;
    }
  }  // namespace prstrg
}  // namespace coin
