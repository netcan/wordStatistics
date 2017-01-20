## word Statistics
A tool use for figuring word's frequency.

## Demonstration
```bash
$ ./wordStatistics < test.txt > test.csv
$ cat test.csv
word,times
a,18
able,3
accepted,3
account,3
actual,3
advantage,3
again,3
all,3
always,3
and,42
annoyances,3
annoying,3
any,3
anyone,3
are,12
as,3
avoid,2
avoided,3
avoids,6
be,6
because,12
beguiled,3
being,3
belongs,3
best,3
blame,3
blinded,3
born,3
bound,3
business,3
but,15
by,6
can,3
cannot,3
cases,3
certain,3
...
```

## Usage
### Compile
```bash
$ git clone git@github.com:netcan/wordStatistics.git
$ cd wordStatistics
$ make
```
### Run
```bash
$ ./wordStatistics < test.txt > test.csv
```
