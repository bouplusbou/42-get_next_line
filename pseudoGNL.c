/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:38:00 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/30 13:07:41 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
CASES:
I. 500 lines BUFF_SIZE 50, first \n at 15
I. 500 lines BUFF_SIZE 1, first \n at 15

FIND_OR_CREATE
Try to Find the link with corresponding fd
If it exists -> POPULATE_LINE
If it doesn't exist create it and 
									if li doesn't exist create a link and set the li ptr on it
									if li exist add a new link 

READ & IS_LINE?
Read the buf until you find a line
If you got a rest from POPULATE_LINE concatenate rest + big_buf
If you don't find a line populate Line with Big_buf Return 1
Return 0 if nothing comes out from the buf

STOCK_BIG_BUF
Stock what you find in the link

IS_LINE? & POPULATE_LINE
Try to populate Line with a line
If there is a full line populate Line with it, save the rest back in the link and Return 1
If there is no full line save the rest and relaunch READ

Return -1 errors

read
stock
getoneline
leftover?


