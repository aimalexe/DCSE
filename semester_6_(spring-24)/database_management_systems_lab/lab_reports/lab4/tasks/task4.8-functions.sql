/* Numeric Functions */
SELECT CEILING(1.7);                  -- Returns 2
SELECT COS(PI());                     -- Returns -1
SELECT DEGREES(PI());                 -- Returns 180
SELECT LOG10(100);                    -- Returns 2
SELECT MOD(11, 4);                    -- Returns 3
SELECT RADIANS(180);                  -- Returns PI()
SELECT ROUND(123.4567, 2);            -- Returns 123.46
SELECT SQRT(16);                      -- Returns 4
SELECT TRUNCATE(123.4567, 2);         -- Returns 123.45

/* String Functions */
SELECT CONCAT('Hello', ' ', 'World');         -- Returns 'Hello World'
SELECT UPPER('hello');                        -- Returns 'HELLO'
SELECT LOWER('HELLO');                        -- Returns 'hello'
SELECT REPEAT('MySQL ', 3);                   -- Returns 'MySQL MySQL MySQL '
SELECT REVERSE('abcd');                       -- Returns 'dcba'
SELECT 'abc' REGEXP '^[a-z]$';               -- Returns 1 if 'abc' matches the regular expression
SELECT REPLACE('Hello World', 'World', 'MySQL'); -- Returns 'Hello MySQL'
SELECT LENGTH('Hello World');                 -- Returns 11
SELECT LTRIM('   Hello World');               -- Returns 'Hello World' with leading spaces removed
SELECT RTRIM('Hello World   ');               -- Returns 'Hello World' with trailing spaces removed

/* Date And Time Functions */
SELECT CURDATE();                        -- Returns the current date
SELECT WEEK(CURDATE());                  -- Returns the week number for the current date
SELECT CURDATE() + INTERVAL 1 DAY;       -- Returns the date one day from the current date
SELECT QUARTER(CURDATE());               -- Returns the quarter of the year for the current date
SELECT NOW();                            -- Returns the current date and time
SELECT SYSDATE();                        -- Returns the current date and time (similar to NOW())
SELECT DATE_FORMAT(NOW(), '%Y-%m-%d');   -- Returns the current date in YYYY-MM-DD format
