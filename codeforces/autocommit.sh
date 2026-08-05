#!/bin/bash

if [ -n "$(gti status --porcelain)"];
	then 
		echo "changes detected . Automating commit"

	git add .

	COMMITG_MSG="New coding problem solved yay $(date '+%Y-%m-%d %H:%M:%S')"
	git commit -m "$COMMIT_MSG"

	BRANCH=$(git branch --show-current)

	git push origin "$BRANCH"
	echo "successfuly pushed to $BRANCH!"

else 
	echo "NO COMMIT SAAR DONOT REEDEM SAAR"

fi
