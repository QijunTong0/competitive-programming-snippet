struct point
{
    int x, y;
};
bool detect(point p0, point p1, point q0, point q1)
{
    int t0 = (p1.x - p0.x) * (q0.y - p0.y) - (p1.y - p0.y) * (q0.x - p0.x);
    int t1 = (p1.x - p0.x) * (q1.y - p0.y) - (p1.y - p0.y) * (q1.x - p0.x);
    int u0 = (q1.x - q0.x) * (p0.y - q0.y) - (q1.y - q0.y) * (p0.x - q0.x);
    int u1 = (q1.x - q0.x) * (p1.y - q0.y) - (q1.y - q0.y) * (p1.x - q0.x);
    return (t0 * t1 < 0 && u0 * u1 < 0);
}