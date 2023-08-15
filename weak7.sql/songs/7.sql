SELECT avg(energy) as "AVG Drake" FROM songs, artists
WHERE songs.artist_id=artists.id and artists.name ="Drake";