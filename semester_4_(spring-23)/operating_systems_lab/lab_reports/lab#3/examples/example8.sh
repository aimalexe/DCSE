while echo "Please enter command"
read response
do
     case "$response" in
 	    'done') break 
		       ;;
	        "")     continue
			 ;;
	         *) eval $response
			;;
	esac
done

