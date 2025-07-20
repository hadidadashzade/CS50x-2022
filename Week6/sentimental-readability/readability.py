# TODO
def main():
    text = input("Text: ")
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)
    L = 100 * (letters / words)
    S = 100 * (sentences / words)
    index = round(0.0588 * L - 0.296 * S - 15.8)
    if index < 1:
        print("Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


def count_letters(text):
    countlet = 0
    for c in text:
        if (c.isalpha()) == True:
            countlet += 1
    return countlet


def count_words(text):
    countwor = 1
    for c in text:
        space = 32
        if c == chr(space):
            countwor += 1
    return countwor


def count_sentences(text):
    countsen = 0
    for c in text:
        exclam = 33
        period = 46
        quest = 63
        
        if c == chr(exclam) or c == chr(period) or c == chr(quest):
            countsen += 1
    return countsen


main()