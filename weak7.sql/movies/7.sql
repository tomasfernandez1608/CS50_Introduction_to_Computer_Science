SELECT title, rating FROM movies, ratings
WHERE movies.year = 2010 AND id=movie_id
ORDER BY rating DESC, title;