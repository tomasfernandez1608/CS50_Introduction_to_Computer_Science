SELECT people.name FROM people, stars, movies
WHERE people.id=stars.person_id AND movies.id=stars.movie_id
AND movies.id IN (SELECT movies.id FROM people, stars, movies
WHERE people.id=stars.person_id AND movies.id=stars.movie_id
AND people.name ="Kevin Bacon" AND people.birth =1958)
AND people.name != "Kevin Bacon";