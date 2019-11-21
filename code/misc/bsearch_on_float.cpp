float l_real = 0.0f, r_real = 1e14f;
uint32_t l = reinterpret_cast<uint32_t&>(l_real), r = reinterpret_cast<uint32_t&>(r_real);
while (l < r) {
    uint32_t mid = l + (r - l) / 2;
    if (check(reinterpret_cast<float&>(mid)))
        r = mid;
    else
        l = mid + 1;
}
