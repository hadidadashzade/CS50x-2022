import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    db = sys.argv[1]
    sq = sys.argv[2]
    # TODO: Read database file into a variable
    with open(db, "r") as file:
        database = csv.reader(file)
        subsequence = []
        for row in database:
            for i in range(len(row)):
                if i != 0:
                    subsequence.append(row[i])
            break
    # TODO: Read DNA sequence file into a variable
    with open(sq, "r") as f:
        sequence = f.read()
    # TODO: Find longest match of each STR in DNA sequence
    pattern = []
    for i in subsequence:
        pattern.append(longest_match(sequence, i))
    # TODO: Check database for matching profiles
    with open(db, "r") as fl:
        dictionary = csv.DictReader(fl)
        for row in dictionary:
            counter = 0
            for k in range(len(subsequence)):
                if int(row[subsequence[k]]) == pattern[k]:
                    counter += 1
                    if counter == len(subsequence):
                        print(row["name"])
                        exit()
        print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1
            
            # If there is no match in the substring
            else:
                break
        
        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
