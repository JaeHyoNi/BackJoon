road[from][to] = road[from][mid];
                    road[from][to].push_back(mid);
                    road[from][to] =road[from][to] + road[mid][to];