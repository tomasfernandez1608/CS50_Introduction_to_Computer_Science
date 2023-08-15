SELECT people.name FROM people, ratings, movies, directors
WHERE ratings.rating >= 9.0
AND movies.id=ratings.movie_id
AND directors.person_id=people.id
AND directors.movie_id=movies.id
ORDER BY people.name;