SELECT avg(rating) FROM ratings, movies
WHERE movies.id=ratings.movie_id AND movies.year=2012;