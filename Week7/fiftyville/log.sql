-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT description
FROM crime_scene_reports
WHERE day = 28
AND month = 7
AND year = 2021
AND street = "Humphrey Street";

SELECT name, transcript
FROM interviews
WHERE day = 28
AND month = 7
AND year = 2021
AND transcript LIKE '%bakery%';

SELECT license_plate, activity
FROM bakery_security_logs
WHERE day = 28
AND month = 7
AND year = 2021
AND hour = 10
AND minute <= 25
AND minute >= 15;

SELECT account_number, amount
FROM atm_transactions
WHERE day = 28
AND month = 7
AND year = 2021
AND atm_location = "Leggett Street"
AND transaction_type = "withdraw";

SELECT abbreviation, full_name, city, flights.hour, flights. minute, flights.id
FROM airports
JOIN flights ON airports.id = destination_airport_id
WHERE(
    SELECT destination_airport_id
    FROM flights
    WHERE (
        SELECT id
        FROM airports
        WHERE city = "Fiftyville"
    ) = origin_airport_id
    AND day = 29
    AND month = 7
    AND year = 2021
    ORDER BY hour ASC, minute ASC
    LIMIT 1
) = airports.id
ORDER BY hour ASC, minute ASC
LIMIT 1;

SELECT name
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE people.license_plate = "5P2BI95"
    OR people.license_plate = "94KL13X"
    OR people.license_plate = "6P58WS2"
    OR people.license_plate = "4328GD8"
    OR people.license_plate = "G412CB7"
    OR people.license_plate = "L93JTIZ"
    OR people.license_plate = "322W7JE"
    OR people.license_plate = "0NTHK55"
AND bank_accounts.account_number = 28500762
    OR bank_accounts.account_number = 28296815
    OR bank_accounts.account_number = 76054385
    OR bank_accounts.account_number = 49610011
    OR bank_accounts.account_number = 16153065
    OR bank_accounts.account_number = 25506511
    OR bank_accounts.account_number = 81061156
    OR bank_accounts.account_number = 26013199
INTERSECT
SELECT name
FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON passengers.flight_id = flights.id
WHERE flights.id = 36;

SELECT name, phone_number
FROM people
WHERE name = "Bruce"
OR name = "Kenny"
OR name = "Luca"
OR name = "Taylor";

SELECT people.name, caller, receiver, duration, day
FROM phone_calls
JOIN people ON phone_calls.caller = people.phone_number
wHERE name = "Kenny"
OR name = "Bruce"
OR name = "Luca"
OR name = "Taylor"
AND duration < 60
AND month = 7
AND year = 2021
AND day = 28;

-- 9. Get receiver names

SELECT name, phone_number
FROM people
WHERE phone_number = "(375) 555-8161"
OR phone_number = "(676) 555-6554"
OR phone_number = "(066) 555-9701";