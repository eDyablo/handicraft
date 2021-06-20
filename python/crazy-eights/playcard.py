from random import shuffle


class Suite:
    def __init__(self, name, pip):
        self.__name = name
        self.__pip = pip

    def __str__(self):
        return str(self.__pip)


class Card:
    def __init__(self, suite, rank, face):
        self.__face = face
        self.__rank = rank
        self.__suite = suite

    def __str__(self):
        return ''.join(map(str, [
            self.__suite,
            self.__face,
        ]))


class Deck:
    def __init__(self):
        self.__cards = []

    def __str__(self):
        return ' '.join(map(str, self.__cards))

    def put(self, card):
        self.__cards.append(card)

    def shuffle(self):
        shuffle(self.__cards)

    def draw(self):
        return self.__cards.pop()

    def copy(self):
        deck = Deck()
        deck.__cards = self.__cards[:]
        return deck

    def enumerate(self):
        return enumerate(self.__cards)


class EnglishPattern:
    def __init__(self):
        self.__suites = [
            Suite('hearts', '♥'),
            Suite('spades', '♠'),
            Suite('clubs', '♣'),
            Suite('diamands', '♦'),
        ]

    def build_deck(self):
        deck = Deck()
        for suite in self.__suites:
            deck.put(Card(suite, 'ace', 'A'))
            for i in range(2, 11):
                deck.put(Card(suite, i, str(i)))
            deck.put(Card(suite, 'jack', 'J'))
            deck.put(Card(suite, 'queen', 'Q'))
            deck.put(Card(suite, 'king', 'K'))
        return deck
