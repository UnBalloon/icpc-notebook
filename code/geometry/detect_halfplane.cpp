// abs(point a) = absolute value of a
// ccw(a, b, c) = a.ccw(b, c)
pair<bool, point> half_inter(vector<pair<point,point> > &vet){
    random_shuffle(all(vet));
    point p;
    rep(i,0,sz(vet)) if(ccw(vet[i].x,vet[i].y,p) != 1){
        point dir = (vet[i].y - vet[i].x) / abs(vet[i].y - vet[i].x);
        point l = vet[i].x - dir*1e15;
        point r = vet[i].x + dir*1e15;
        if(r < l) swap(l, r);
        rep(j, 0, i){
            if(ccw(point(), vet[i].x-vet[i].y, vet[j].x-vet[j].y) == 0){
                if(ccw(vet[j].x, vet[j].y, p) == 1)
                    continue;
                return mp(false, point());
            }
            if(ccw(vet[j].x, vet[j].y, l) != 1)
                l = max(l, line_intersect(vet[i].x,vet[i].y,vet[j].x,vet[j].y));
            if(ccw(vet[j].x, vet[j].y, r) != 1)
                r = min(r, line_intersect(vet[i].x,vet[i].y,vet[j].x,vet[j].y));
            if(!(l < r)) return mp(false, point());
        }
        p = r;
    }
    return mp(true, p);
}
