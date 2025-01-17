/*-----------------------------------------------------------------------
Licensed to the Apache Software Foundation (ASF) under one
or more contributor license agreements.  See the NOTICE file
distributed with this work for additional information
regarding copyright ownership.  The ASF licenses this file
to you under the Apache License, Version 2.0 (the
"License"; you may not use this file except in compliance
with the License.  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied.  See the License for the
specific language governing permissions and limitations
under the License.
-----------------------------------------------------------------------*/

#include "etp/ssl/SslClientSession.h"

using namespace ETP_NS;

SslClientSession::SslClientSession(boost::asio::io_context& ioc, boost::asio::ssl::context& ctx,
	const std::string & host, const std::string & port, const std::string & target, const std::string & authorization,
	const std::vector<Energistics::Etp::v12::Datatypes::SupportedProtocol> & requestedProtocols,
	const std::vector<std::string>& supportedObjects)
	: AbstractClientSession<SslClientSession>(ioc, host, port, target, authorization,
		requestedProtocols, supportedObjects),
	ws_(ioc, ctx)
{
	ws_.binary(true);
}
