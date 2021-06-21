from random import shuffle


class Suite(object):
    def __init__(self, name, pip):
        self.__name = name
        self.__pip = pip

    def __str__(self):
        return str(self.__pip)

    @property
    def name(self):
        return self.__name

    @property
    def pip(self):
        return self.__pip


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

    @property
    def face(self):
        return self.__face

    @property
    def rank(self):
        return self.__rank

    @property
    def suite(self):
        return self.__suite


class Deck(object):
    def __init__(self):
        self.__cards = []

    def __str__(self):
        return ' '.join(map(str, self.__cards))

    @property
    def cards(self):
        return self.__cards[:]

    def put(self, card):
        self.__cards.append(card)

    def shuffle(self):
        shuffle(self.__cards)

    def draw(self, card_id=None):
        if card_id is not None and card_id >= 0 and card_id < len(self.__cards):
            card = self.__cards[card_id]
            self.__cards.remove(card)
            return card
        if len(self.__cards):
            return self.__cards.pop()

    def top(self):
        if len(self.__cards):
            return self.__cards[-1]


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
