SELECT title FROM people, ratings, movies, stars
WHERE movies.id=ratings.movie_id
AND people.id=stars.person_id
AND people.name="Chadwick Boseman"
AND stars.movie_id=movies.id
ORDER BY rating DESC LIMIT 5;