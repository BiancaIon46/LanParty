I chose to make a header file for each type of structure used (queue, stack, bst, avl) + for the team and player information reading functions. 
	
Requirement 2
	The number of teams to remain in the game must be a power of 2, so from the number of teams subtract the difference to the nearest power of 2. (NoToDelete = number of teams to be deleted)
	deleteTeamByScore() - delete teams with the lowest score by going through the entire list of teams, keeping in mind the current number and its previous number. I treat the case where the node to delete is = headTeam and the case where it is any node.

Requirement 3
	I have chosen to have the matches represented by a 2-element dataTeam queue, in which the teams entering the match are retained. Teams are placed in the queue by going through the list of teams 2 by 2. 
	The number of rounds with the round variable, which they pass as a parameter. round is incremented by 1 for each entry in the loop. After each match the number of teams is halved (NoTeams /=2)
 	getWinnersAndLosers() - creates my 2 stacks of winners and losers at the same time, removing the items from the matches queue.
	createMatchesFromStack() - creates the next set of matches using the winners stack. 
	 
Requirement 4
	In requirement 3, when I reach NoTeams = 8, I create my BST, based on the score, by going through the entire stack of winners.
	printBst() - in order to have the scores in descending order I run through the BST.

Requirement 5
	populateAvl() - populate my AVL by inserting each element of the BST into the tree.
