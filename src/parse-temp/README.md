# Parsing example

## Motivation

The original inquiry involved processing a temperature reading from an API.
We could actually come up with an improved solution involving making the response format easier to work with in the first place.
Anyway, we decided to still discuss how the original grammar could have been parsed.
Note that not all of the implementations behave exactly the same on invalid input and border conditions.

## Grammar

```
/^[^\"]*\"([^,:]*)(,[^:]*)?:([+-]?[0-9]+).*$/
```

## Test inputs

* `"City:-10°C"`
* `"City,estimated:+10°C"`
