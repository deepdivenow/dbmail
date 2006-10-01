/*
 *  Copyright (c) 2005-2006 NFG Net Facilities Group BV support@nfg.nl
 *
 *  licence: GPLv2
 *  see COPYING for details.
 *  
 */

#include "dbmail.h"

char *configFile = "/etc/dbmail/dbmail-test.conf";


/* simple testmessages. */

char *rfc822 = "From nobody Wed Sep 14 16:47:48 2005\n"
	"Content-Type: text/plain; charset=\"us-ascii\"\n"
	"MIME-Version: 1.0\n"
	"Content-Transfer-Encoding: 7bit\n"
	"To: testuser@foo.org\n"
	"From: somewher@foo.org\n"
	"Subject: dbmail test message\n"
	"\n"
	"\n"
	"    this is a test message\n"
	"\n";
    
char *multipart_message = "From: \"Brother from another planet\" <vol@inter7.com>\n"
	"To: \"Brother from another planet\" <vol@inter7.com>\n"
	"Reply-to: \"Brother from another planet\" <vol@inter7.com>\n"
	"Cc: \"Brother from another planet\" <vol@inter7.com>,\n"
	" \"SpongeBob O'Brien\" <nobody@test123.com>\n"
	"Subject: multipart/mixed\n"
	"References: <5.1.0.14.0.20020926105718.01c0a568@mail>\n"
	"               <5.1.0.14.0.20020926105718.01c0a568@mail>\n"
	"Date: Wed, 11 May 2005 13:20:08 -0700\n"
	"Received: at mx.inter7.com from localhost\n"
	"Received: at localhost from localhost\n"
	"Received: at localhost from localhost\n"
	"MIME-Version: 1.0\n"
	"Content-type: multipart/mixed; boundary=boundary\n"
	"X-Dbmail-ID: 12345\n"
	"\n"
	"MIME multipart messages specify that there are multiple\n"
	"messages of possibly different types included in the\n"
	"message.  All peices will be availble by the user-agent\n"
	"if possible.\n"
	"\n"
	"The header 'Content-disposition: inline' states that\n"
	"if possible, the user-agent should display the contents\n"
	"of the attachment as part of the email, rather than as\n"
	"a file, or message attachment.\n"
	"\n"
	"(This message will not be seen by the user)\n"
	"\n"
	"--boundary\n"
	"Content-type: text/html\n"
	"Content-disposition: inline\n"
	"\n"
	"Test message one\n"
	"--boundary\n"
	"Content-type: text/plain; charset=us-ascii; name=testfile\n"
	"Content-transfer-encoding: base64\n"
	"\n"
	"IyEvYmluL2Jhc2gNCg0KY2xlYXINCmVjaG8gIi4tLS0tLS0tLS0tLS0tLS0t\n"
	"LS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS4i\n"
	"DQplY2hvICJ8IE1hcmNoZXcuSHlwZXJyZWFsIHByZXNlbnRzOiB2aXhpZSBj\n"
	"cm9udGFiIGV4cGxvaXQgIzcyODM3MSB8Ig0KZWNobyAifD09PT09PT09PT09\n"
	"PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09\n"
	"PT09fCINCmVjaG8gInwgU2ViYXN0aWFuIEtyYWhtZXIgPGtyYWhtZXJAc2Vj\n"
	"dXJpdHkuaXM+ICAgICAgICAgICAgICAgICAgIHwiDQplY2hvICJ8IE1pY2hh\n"
	"--boundary--\n";
	
char *multipart_alternative = "From paul@nfg.nl Tue Oct 11 13:06:24 2005\n"
	"Message-ID: <43E5FE98.4030609@nfg.nl>\n"
	"Date: Sun, 05 Feb 2006 14:33:12 +0100\n"
	"From: Paul J Stevens <paul@nfg.nl>\n"
	"Organization: NFG Net Facilities Group BV\n"
	"User-Agent: Debian Thunderbird 1.0.2 (X11/20051002)\n"
	"X-Accept-Language: en-us, en\n"
	"To: paul@nfg.nl\n"
	"Subject: test\n"
	"X-Enigmail-Version: 0.91.0.0\n"
	"X-DBMail-PhysMessage-ID: 841010\n"
	"MIME-Version: 1.0\n"
	"Content-Type: multipart/mixed; boundary=------------050000030206040804030909\n"
	"\n"
	"This is a multi-part message in MIME format.\n"
	"--------------050000030206040804030909\n"
	"Content-Type: multipart/alternative; boundary=\"------------040302030903000400040101\"\n"
	"\n"
	"\n"
	"--------------040302030903000400040101\n"
	"Content-Type: text/plain; charset=ISO-8859-1\n"
	"Content-Transfer-Encoding: 7bit\n"
	"\n"
	"\n"
  	"test\n"
	"\n"
	"-- \n"
  	"________________________________________________________________\n"
  	"Paul Stevens                                  mailto:paul@nfg.nl\n"
  	"NET FACILITIES GROUP                     PGP: finger paul@nfg.nl\n"
  	"The Netherlands________________________________http://www.nfg.nl\n"
	"\n"
	"\n"
	"--------------040302030903000400040101\n"
	"Content-Type: text/html; charset=ISO-8859-1\n"
	"Content-Transfer-Encoding: 7bit\n"
	"\n"
	"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">\n"
	"<html>\n"
	"<head>\n"
  	"<meta content=\"text/html;charset=ISO-8859-1\" http-equiv=\"Content-Type\">\n"
  	"<title></title>\n"
	"</head>\n"
	"<body bgcolor=\"#ffffff\" text=\"#000000\">\n"
	"<h1>test</h1>\n"
	"<pre class=\"moz-signature\" cols=\"72\">-- \n"
  	"________________________________________________________________\n"
  	"Paul Stevens                                  <a class=\"moz-txt-link-freetext\" href=\"mailto:paul@nfg.nl\">mailto:paul@nfg.nl</a>\n"
  	"NET FACILITIES GROUP                     PGP: finger <a class=\"moz-txt-link-abbreviated\" href=\"mailto:paul@nfg.nl\">paul@nfg.nl</a>\n"
  	"The Netherlands________________________________<a class=\"moz-txt-link-freetext\" href=\"http://www.nfg.nl\">http://www.nfg.nl</a>\n"
	"</pre>\n"
	"</body>\n"
	"</html>\n"
	"\n"
	"--------------040302030903000400040101--\n"
	"\n"
	"--------------050000030206040804030909\n"
	"Content-Type: image/jpeg; name=\"jesse_2.jpg\"\n"
	"Content-Transfer-Encoding: base64\n"
	"Content-Disposition: inline; filename=\"jesse_2.jpg\"\n"
	"\n"
	"/9j/4AAQSkZJRgABAQEASABIAAD/4RirRXhpZgAASUkqAAgAAAAJAA8BAgAGAAAAegAAABAB\n"
	"AgAWAAAAgAAAABIBAwABAAAABgAAABoBBQABAAAAlgAAABsBBQABAAAAngAAACgBAwABAAAA\n"
	"4SSSAjbtIaCVfBmeySSaBgF/QFxTe0wJwuA1XS6lm9zCPS6TTckkozVoEzHvqhq6WySQ6mYI\n"
	"7LF3kd0klwPUfuX7HS032seT7fokkkufZpP/2Q==\n"
	"--------------050000030206040804030909--\n";


char *outlook_multipart = "From aprilbabies-bounces@lists.nfg.nl  Fri Nov 25 22: 34:35 2005\n"
	"From: \"Foo Bar\" <foobar@foo.bar>\n"
	"To: \"My List...\" <mylist@foo.bar>\n"
	"Subject: RE: [MyList] blah\n"
	"Date: Fri, 25 Nov 2005 22:34:16 +0100\n"
	"Message-ID: <IFEIKJKAMPLPGJIEIMEECEIFEDAA.ka@sus.se>\n"
	"MIME-Version: 1.0\n"
	"Content-Type: multipart/mixed;\n"
	"	boundary=\"===============0825346837==\"\n"
	"\n"
	"--===============0825346837==\n"
	"Content-Type: text/plain;\n"
	"	charset=\"Windows-1252\"\n"
	"Content-Transfer-Encoding: 7bit\n"
	"\n"
	"test\n"
	"\n"
	"\n"
	"--===============0825346837==\n"
	"Content-Type: text/plain; charset=\"iso-8859-1\"\n"
	"MIME-Version: 1.0\n"
	"Content-Transfer-Encoding: quoted-printable\n"
	"Content-Disposition: inline\n"
	"\n"
	"my sig.\n"
	"--===============0825346837==--\n"
	"\n";

/* raw_lmtp_data is equal to multipart_message, except for the line-endings
 * and the termination dot.
 */
char *raw_lmtp_data = "From: \"Brother from another planet\" <vol@inter7.com>\r\n"
	"To: \"Brother from another planet\" <vol@inter7.com>\r\n"
	"Subject: multipart/mixed\r\n"
	"Reply-to: \"Brother from another planet\" <vol@inter7.com>\r\n"
	"Cc: \"Brother from another planet\" <vol@inter7.com>,\r\n"
	" \"SpongeBob O'Brien\" <nobody@test123.com>\r\n"
	"Date: Wed, 11 May 2005 13:20:08 -0700\n"
	"Received: at mx.inter7.com from localhost\r\n"
	"Received: at localhost from localhost\r\n"
	"MIME-Version: 1.0\r\n"
	"Content-type: multipart/mixed; boundary=\"boundary\"\r\n"
	"X-Dbmail-ID: 12345\r\n"
	"\r\n"
	"MIME multipart messages specify that there are multiple\r\n"
	"messages of possibly different types included in the\r\n"
	"message.  All peices will be availble by the user-agent\r\n"
	"if possible.\r\n"
	"\r\n"
	"The header 'Content-disposition: inline' states that\r\n"
	"if possible, the user-agent should display the contents\r\n"
	"of the attachment as part of the email, rather than as\r\n"
	"a file, or message attachment.\r\n"
	"\r\n"
	"(This message will not be seen by the user)\r\n"
	"\r\n"
	"--boundary\r\n"
	"Content-type: text/html\r\n"
	"Content-disposition: inline\r\n"
	"\r\n"
	"Test message one\r\n"
	"--boundary\r\n"
	"Content-type: text/plain; charset=us-ascii; name=\"testfile\"\r\n"
	"Content-transfer-encoding: base64\r\n"
	"\r\n"
	"IyEvYmluL2Jhc2gNCg0KY2xlYXINCmVjaG8gIi4tLS0tLS0tLS0tLS0tLS0t\r\n"
	"LS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS4i\r\n"
	"DQplY2hvICJ8IE1hcmNoZXcuSHlwZXJyZWFsIHByZXNlbnRzOiB2aXhpZSBj\r\n"
	"cm9udGFiIGV4cGxvaXQgIzcyODM3MSB8Ig0KZWNobyAifD09PT09PT09PT09\r\n"
	"PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09\r\n"
	"PT09fCINCmVjaG8gInwgU2ViYXN0aWFuIEtyYWhtZXIgPGtyYWhtZXJAc2Vj\r\n"
	"dXJpdHkuaXM+ICAgICAgICAgICAgICAgICAgIHwiDQplY2hvICJ8IE1pY2hh\r\n"
	"--boundary--\r\n"
	".\r\n";

char *simple_message_part = "Content-Type: text/plain; charset=\"iso-8859-1\"\n"
	"MIME-Version: 1.0\n"
	"Content-Transfer-Encoding: quoted-printable\n"
	"Content-Disposition: inline\n"
	"\n"
	"my sig.\n";

char *multipart_message_part = "Content-Type: text/plain;\n"
	" name=\"mime_alternative\"\n"
	"Content-Transfer-Encoding: 7bit\n"
	"Content-Disposition: inline;\n"
	" filename=\"mime_alternative\"\n"
	"\n"
	"From: <vol@inter7.com>\n"
	"To: <vol@inter7.com>\n"
	"Subject: multipart/alternative\n"
	"MIME-Version: 1.0\n"
	"Content-type: multipart/alternative; boundary=\"boundary\"\n"
	"\n"
	"MIME alternative sample body\n"
	"(user never sees this portion of the message)\n"
	"\n"
	"These messages are used to send multiple versions of the same\n"
	"message in different formats.  User-agent will decide which\n"
	"to display.\n"
	"\n"
	"--boundary\n"
	"Content-type: text/html\n"
	"\n"
	"<HTML><HEAD><TITLE>HTML version</TITLE></HEAD><BODY>\n"
	"<CENTER>HTML version</CENTER>\n"
	"</BODY></HTML>\n"
	"--test\n"
	"Content-type: text/plain\n"
	"\n"
	"Text version\n"
	"--boundary--\n"
	"\n";

char *encoded_message_koi = "From: =?koi8-r?Q?=E1=CE=D4=CF=CE=20=EE=C5=C8=CF=D2=CF=DB=C9=C8=20?=<bad@foo.ru>\n"
	"To: nobody@foo.ru\n"
	"Subject: test\n"
	"MIME-Version: 1.0\n"
	"Content-Type: text/plain\n"
	"\n"
	"test mail\n\n";

char *encoded_message_latin = "From: =?iso-8859-1?Q?B=BA_V._F._Z=EAzere?= <nobody@nowhere.org>\n"
	"To: nobody@foo.org\n"
	"Subject: =?iso-8859-1?Q?Re:_M=F3dulo_Extintores?=\n"
	"MIME-Version: 1.0\n"
	"Content-Type: text/plain\n"
	"\n"
	"test\n\n";

