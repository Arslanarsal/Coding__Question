import random
import json


def save_scores(scores):
    with open("leaderboard.json", "w") as file:
        json.dump(scores, file, indent=4)


def load_scores():
    try:
        with open("leaderboard.json", "r") as file:
            return json.load(file)
    except FileNotFoundError:
        return []


def display_leaderboard():
    scores = load_scores()
    if scores:
        print("\nLeaderboard:")
        print("Rank | Name       | Guesses | Guessed Numbers")
        print("---------------------------------------------")
        for rank, entry in enumerate(sorted(scores, key=lambda x: x['guesses']), start=1):
            print(f"{rank:4} | {entry['name']:<10} | {entry['guesses']:7} | {', '.join(map(str, entry['guessed_numbers']))}")
    else:
        print("\nNo scores recorded yet.")

# Main game logic
def play_game():
    print("Welcome to the Number Guessing Game!")   

    scores = load_scores()

    # Choose difficulty level
    print("Choose a difficulty level:")
    print("1. Easy (1-100, 10 attempts)")
    print("2. Hard (1-50, 5 attempts)")

    while True:
        try:
            difficulty = int(input("Enter your choice (1 or 2): "))
            if difficulty == 1:
                max_number, max_attempts = 100, 10
                break
            elif difficulty == 2:
                max_number, max_attempts = 100, 5
                break
            else:
                print("Invalid choice. Please choose 1 or 2.")
        except ValueError:
            print("Invalid input. Please enter a number.")

    secret_number = random.randint(1, max_number)
    guessed_numbers = []

    print(f"\nI'm thinking of a number between 1 and {max_number}. You have {max_attempts} attempts to guess it.")

    for attempt in range(1, max_attempts + 1):
        while True:
            try:
                guess = int(input(f"Attempt {attempt}/{max_attempts}: Your guess: "))
                if 1 <= guess <= max_number:
                    break
                else:
                    print(f"Please guess a number between 1 and {max_number}.")
            except ValueError:
                print("Invalid input. Please enter a number.")

        guessed_numbers.append(guess)

        if guess < secret_number:
            print("BHAI JAN CHOTA HA BARA DALYN :)")
        elif guess > secret_number:
            print("BHAI JAN BARA HAA THORA CHOTA DALYN :(")
        else:
            print(f"Congratulations! You guessed the number {secret_number} in {attempt} attempts.")
            name = input("Enter your name: ")
            scores.append({"name": name, "guesses": attempt, "guessed_numbers": guessed_numbers})
            save_scores(scores)
            display_leaderboard()
            return

    print(f"Sorry, you've used all {max_attempts} attempts. The number was {secret_number}.")
    display_leaderboard()

# Multiplayer mode
def multiplayer_mode():
    print("\nMultiplayer Mode:")
    num_players = int(input("Enter the number of players: "))

    players = []
    for i in range(1, num_players + 1):
        name = input(f"Enter name for Player {i}: ")
        players.append({"name": name, "guesses": 0, "guessed_numbers": []})

    max_number = 100
    secret_number = random.randint(1, max_number)
    print(f"\nThe secret number is between 1 and {max_number}.")

    turn = 0
    while True:
        current_player = players[turn % num_players]
        name = current_player['name']

        while True:
            try:
                guess = int(input(f"{name}'s turn. Guess the number: "))
                if 1 <= guess <= max_number:
                    break
                else:
                    print(f"Please guess a number between 1 and {max_number}.")
            except ValueError:
                print("Invalid input. Please enter a number.")

        current_player['guessed_numbers'].append(guess)
        current_player['guesses'] += 1

        if guess < secret_number:
            print("Too low!")
        elif guess > secret_number:
            print("Too high!")
        else:
            print(f"{name} wins! The number was {secret_number}.")
            save_scores(players)
            display_leaderboard()
            return

        turn += 1


def main():
    while True:
        print("\nMain Menu:")
        print("1. Single Player Mode")
        print("2. Multiplayer Mode")
        print("3. View Leaderboard")
        print("4. Quit")

        choice = input("Enter your choice: ")
        if choice == "1":
            play_game()
        elif choice == "2":
            multiplayer_mode()
        elif choice == "3":
            display_leaderboard()
        elif choice == "4":
            print("Apki Tashreef Awri k lia bohot Dhanywaad!")
            break
        else:
            print("Bhai Jan Ya nai Ha Sai wala dalyn dubara!")

if __name__ == "__main__":
    main()
