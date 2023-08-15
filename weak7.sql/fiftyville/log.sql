-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Find crime description
SELECT description
FROM crime_scene_reports
WHERE month=7 AND day=28
AND street='Humphrey Street';

Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |
| Littering took place at 16:36. No known witnesses.

SELECT * FROM interviews WHERE day=28 AND month=7 AND year=2021;
En algún momento dentro de los diez minutos del robo, vi al ladrón subirse a un automóvil en el estacionamiento de la panadería y alejarse.
 Si tiene imágenes de seguridad del estacionamiento de la panadería,
es posible que desee buscar autos que hayan salido del estacionamiento en ese período de tiempo.
----
No sé el nombre del ladrón, pero era alguien a quien reconocí. Esta mañana, antes de llegar a la panadería de Emma,
​​estaba caminando por ATM on Leggett Street y vi al ladrón que estaba retirando algo de dinero.
---
Cuando el ladrón salía de la panadería, llamaron a alguien que les habló durante menos de un minuto.
En la llamada, escuché al ladrón decir que planeaban tomar el primer vuelo de Fiftyville mañana.
 Luego, el ladrón le pidió a la persona al otro lado del teléfono que comprara el boleto de avión.
---

-- See the entrance and exit in that moment

SELECT * FROM bakery_security_logs
WHERE month=7 AND day=28 AND year=2021 AND activity='exit' AND hour=10 AND minute>15 AND minute<26;
| id  | year | month | day | hour | minute | activity | license_plate |
+-----+------+-------+-----+------+--------+----------+---------------+
| 260 | 2021 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
| 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
| 262 | 2021 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
| 263 | 2021 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
| 264 | 2021 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
| 265 | 2021 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
| 266 | 2021 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
| 267 | 2021 | 7     | 28  | 10   | 23     | exit     | 0NTHK55


-- CHECK ATM

SELECT * FROM atm_transactions
WHERE year=2021 AND month=7 AND day=28 AND atm_location='Leggett Street'
AND transaction_type='withdraw';

id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
+-----+----------------+------+-------+-----+----------------+------------------+--------+
| 246 | 28500762       | 2021 | 7     | 28  | Leggett Street | withdraw         | 48     |
| 264 | 28296815       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
| 266 | 76054385       | 2021 | 7     | 28  | Leggett Street | withdraw         | 60     |
| 267 | 49610011       | 2021 | 7     | 28  | Leggett Street | withdraw         | 50     |
| 269 | 16153065       | 2021 | 7     | 28  | Leggett Street | withdraw         | 80     |
| 288 | 25506511       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
| 313 | 81061156       | 2021 | 7     | 28  | Leggett Street | withdraw         | 30     |
| 336 | 26013199       | 2021 | 7     | 28  | Leggett Street | withdraw         | 35     |
+-----+----------------+------+-------+-----+----------------+------------------+--------+

-- Buscar las llamadas de ese dia
SELECT * FROM phone_calls
WHERE year=2021 AND month=7 AND day =28 AND duration<60;
id  |     caller     |    receiver    | year | month | day | duration |
+-----+----------------+----------------+------+-------+-----+----------+
| 221 | (130) 555-0289 | (996) 555-8899 | 2021 | 7     | 28  | 51       |
| 224 | (499) 555-9472 | (892) 555-8872 | 2021 | 7     | 28  | 36       |
| 233 | (367) 555-5533 | (375) 555-8161 | 2021 | 7     | 28  | 45       |
| 251 | (499) 555-9472 | (717) 555-1342 | 2021 | 7     | 28  | 50       |
| 254 | (286) 555-6063 | (676) 555-6554 | 2021 | 7     | 28  | 43       |
| 255 | (770) 555-1861 | (725) 555-3243 | 2021 | 7     | 28  | 49       |
| 261 | (031) 555-6622 | (910) 555-3251 | 2021 | 7     | 28  | 38       |
| 279 | (826) 555-1652 | (066) 555-9701 | 2021 | 7     | 28  | 55       |
| 281 | (338) 555-6650 | (704) 555-2131 | 2021 | 7     | 28  | 54

--CHEQUEAR LOS VUELOS
SELECT * FROM passengers
WHERE flight_id IN (SELECT id FROM flights
WHERE origin_airport_id IN (SELECT id FROM airports WHERE city='Fiftyville')
AND day=29 AND year=2021 AND month=7 AND hour < 12);
| flight_id | passport_number | seat |
+-----------+-----------------+------+
| 36        | 7214083635      | 2A   |
| 36        | 1695452385      | 3B   |
| 36        | 5773159633      | 4A   |
| 36        | 1540955065      | 5C   |
| 36        | 8294398571      | 6C   |
| 36        | 1988161715      | 6D   |
| 36        | 9878712108      | 7A   |
| 36        | 8496433585      | 7B   |
| 43        | 7597790505      | 7B   |
| 43        | 6128131458      | 8A   |
| 43        | 6264773605      | 9A   |
| 43        | 3642612721      | 2C   |
| 43        | 4356447308      | 3B   |
| 43        | 7441135547      | 4A

--CONCATENAR LOS DATOS
SELECT * FROM people
WHERE phone_number IN (SELECT caller FROM phone_calls
WHERE year=2021 AND month=7 AND day =28 AND duration<60)
AND license_plate IN (SELECT license_plate FROM bakery_security_logs
WHERE month=7 AND day=28 AND year=2021 AND activity='exit' AND hour=10 AND minute>15 AND minute<26)
AND id IN (SELECT person_id FROM bank_accounts WHERE
account_number IN (SELECT account_number FROM atm_transactions
WHERE year=2021 AND month=7 AND day=28 AND atm_location='Leggett Street'
AND transaction_type='withdraw'))
AND passport_number IN (SELECT passport_number FROM passengers
WHERE flight_id IN (SELECT id FROM flights
WHERE origin_airport_id IN (SELECT id FROM airports WHERE city='Fiftyville')
AND day=29 AND year=2021 AND month=7 AND hour < 12));
-- EL thief WAS Bruce
|   id   | name  |  phone_number  | passport_number | license_plate |
+--------+-------+----------------+-----------------+---------------+
| 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X

-- who do i call bruce?
SELECT * FROM people
WHERE phone_number IN(SELECT receiver FROM phone_calls
WHERE year=2021 AND month=7 AND day =28 AND duration<60 AND caller='(367) 555-5533');
|   id   | name  |  phone_number  | passport_number | license_plate |
+--------+-------+----------------+-----------------+---------------+
| 864400 | Robin | (375) 555-8161 |                 | 4V16VO0
-- WHERE bruce go?
SELECT * FROM airports WHERE
id IN(SELECT destination_airport_id FROM flights
WHERE id IN (SELECT flight_id FROM passengers WHERE passport_number=5773159633));
+----+--------------+-------------------+---------------+
| id | abbreviation |     full_name     |     city      |
+----+--------------+-------------------+---------------+
| 4  | LGA          | LaGuardia Airport | New York City |
+----+--------------+-------------------+---------------+