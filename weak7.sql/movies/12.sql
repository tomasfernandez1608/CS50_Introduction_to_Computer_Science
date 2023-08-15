SELECT title FROM movies, stars, people
WHERE people.name = "Johnny Depp"
AND movies.id=stars.movie_id
AND people.id=stars.person_id
AND title IN (SELECT title FROM movies, stars, people
WHERE people.name = "Helena Bonham Carter"
AND movies.id=stars.movie_id
AND people.id=stars.person_id);