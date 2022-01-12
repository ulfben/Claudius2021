#pragma once
#include <type_traits>
#include <cassert>
// The "xoshiro256** 1.0" generator.
// C++ port by Arthur O'Dwyer (2021).
// Based on the C version by David Blackman and Sebastiano Vigna (2018),
// https://prng.di.unimi.it/xoshiro256starstar.c
static_assert(sizeof(long long) == 8, "64-bit machines only");

class RNG {
 public:
  using u64 = unsigned long long;
  using result_type = u64;
  static constexpr u64 min() noexcept { return 0; }
  static constexpr u64 max() noexcept { return static_cast<u64>(-1); }

  constexpr explicit RNG(u64 seed = 0) noexcept {
    s[0] = splitmix64(seed);
    s[1] = splitmix64(seed);
    s[2] = splitmix64(seed);
    s[3] = splitmix64(seed);
  }

  constexpr explicit RNG(float seed) noexcept
      : RNG(static_cast<u64>(seed)) {}

  constexpr result_type operator()() noexcept {
    const result_type result = rotl(s[1] * 5, 7) * 9;
    const u64 t = s[1] << 17;
    s[2] ^= s[0];
    s[3] ^= s[1];
    s[1] ^= s[2];
    s[0] ^= s[3];
    s[2] ^= t;
    s[3] = rotl(s[3], 45);
    return result;
  }
    
  constexpr result_type operator()(u64 from, u64 to) noexcept {    
    assert(from < to && "RNG: inverted range.");
    const auto result = this->operator()();
    return from + (result % to);
  }

 private:
  u64 s[4]{};

  static constexpr u64 rotl(u64 x, int k) noexcept {
    return (x << k) | (x >> (64 - k));
  }

  static constexpr u64 splitmix64(u64& x) noexcept {
    u64 z = (x += 0x9e3779b97f4a7c15uLL);
    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9uLL;
    z = (z ^ (z >> 27)) * 0x94d049bb133111ebuLL;
    return z ^ (z >> 31);
  }
};