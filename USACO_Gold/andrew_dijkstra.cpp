for (int i = 0; i < pathways; i++)
    {
        fin >> start >> ended >> length ;
        connected[start][ended] = length ;
        connected[ended][start] = length ;
    }
    for (int i = 1; i < farms + 1; i++)
    {
        dist[i] = 1<<30 ;
        visited[i] = false ;
    }
    dist[1] = 0 ;
    int next ;
    for (int i = 1; i < farms + 1; i++)
    {
        next = 1 ;
        cost = 1<<30 ;
        for (int j = 1 ; j < farms + 1 ;j++)
        {
            if (dist[j] < cost && visited[j] == false)
            {
                next = j ;
                cost = dist[j] ;
            }
        }
        visited[next] = true ;
        for (int j = 1 ; j < farms + 1; j++)
        {
            if (connected[next][j] != 0)
            {
                dist[j] = min(dist[j], dist[next] + connected[next][j]) ;
            }
        }
    }