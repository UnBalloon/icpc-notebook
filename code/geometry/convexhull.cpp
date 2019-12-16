// Be sure P has no repeated point if keeping all colinear points.
vector<vec> monotone_chain_ch(vector<vec> P){
    sort(P.begin(), P.end());

    vector<vec> L, U;
    for(auto p : P){
        while(L.size() >= 2 && L[L.size() - 2].ccw(L.back(), p) < 0) // <= to remove colinear points
            L.pop_back();
        L.push_back(p);
    }

    reverse(P.begin(), P.end());
    for(auto p : P){
        while(U.size() >= 2 && U[U.size() - 2].ccw(U.back(), p) < 0)
            U.pop_back();
        U.push_back(p);
    }

    L.pop_back(), U.pop_back();
    L.insert(L.end(), U.begin(), U.end()); 

    return L;
}
