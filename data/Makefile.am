# Copyright (C) 2011 Neal H. Walfield <neal@walfield.org>
#
# Woodchuck is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 3, or (at
# your option) any later version.
#
# Woodchuck is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see
# <http://www.gnu.org/licenses/>.

# To generate the keys:
#
# openssl req -x509 -nodes -days 3650 \
#  -subj '/C=US/ST=MD/L=Baltimore/CN=hssl.cs.jhu.edu' -newkey rsa:2048 \
#  -keyout ssl-receiver.key -out ssl-receiver.cert
#
# See http://www.madboa.com/geek/openssl/#cert-self

# We only include the public key, obviously :-)
dist_pkgdata_DATA = ssl-receiver.cert
